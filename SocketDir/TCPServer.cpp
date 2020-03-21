#include <string>
#include <iostream>
#include <memory>
#include <csignal>
#include <functional>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <string.h>
#include <fcntl.h>

static int setNonBlocking(int fd)
{
	int flags, s;
	flags = fcntl(fd, F_GETFL, 0);
	if (-1 == flags) 
		return -1;
	flags |= O_NONBLOCK;
	s = fcntl(fd, F_SETFL, flags);
	if (-1 == s) 
		return -1;
	return 0;
}

class TCPServer
{
	public:
		TCPServer(const std::string& name):serverName(name)
		{
			// 创建epoll
			epfd = epoll_create(1);
		}
		~TCPServer()
		{
			TEMP_FAILURE_RETRY(::close(epfd));
			if(sockfd != -1)
			{
				::shutdown(sockfd, SHUT_RD);
				TEMP_FAILURE_RETRY(::close(sockfd));
				sockfd = -1;
			}
		}
		TCPServer(const TCPServer&) = delete;
		TCPServer& operator = (const TCPServer&) = delete;
		
		bool bind(const unsigned short port)
		{
			sockfd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		       	if(-1 == sockfd)
			{
				std::cout << "SOCKET FAIL" << std::endl;
				return false;	
			}
			socklen_t size = 64 * 1024;
			::setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &size, sizeof(size));
			::setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &size, sizeof(size));
			int reuse = 1;
			::setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

			struct sockaddr_in addr;
			bzero(&addr, sizeof(addr));
			addr.sin_family = AF_INET;
			addr.sin_addr.s_addr = htonl(INADDR_ANY);
			addr.sin_port = htons(port);
			
			int ret = ::bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
			if(-1 == ret)
			{
				std::cout << "BIND FAIL" << std::endl;
				shutdown();
				return false;
			}
			
			ret = ::listen(sockfd, 5);

			struct epoll_event ev;
			ev.events = EPOLLIN;
			ev.data.ptr = nullptr;
			epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &ev);
			std::cout << "BIND SUCCESS" << std::endl;
			return true;
		}
		int accept(struct sockaddr_in* addr)
		{
			socklen_t len = sizeof(struct sockaddr_in);
			bzero(addr, sizeof(struct sockaddr_in));
			struct epoll_event ev;
			int rc = epoll_wait(epfd, &ev, 1, 500);
			if(1 == rc && (ev.events & EPOLLIN))
				return TEMP_FAILURE_RETRY(::accept(sockfd, (struct sockaddr*)addr, &len));
			return -1;
		}
		void shutdown()
		{
			TEMP_FAILURE_RETRY(::close(epfd));
			if(-1 != sockfd)
			{
				::shutdown(sockfd, SHUT_RD);
				TEMP_FAILURE_RETRY(::close(sockfd));
			}
		}
	private:
		std::string serverName;
		int sockfd = -1;
		int epfd = -1;
};

namespace
{
	std::function<void(int)> shutdown_handler;
	void signal_handler(int signal) { shutdown_handler(signal); }
}

int main(int argc, char** argv)
{
	bool exitFlag = false;
	std::unique_ptr<TCPServer> server = std::make_unique<TCPServer>("小白服务器");
	if(!server)
		return 0;
	server->bind(8500);
	// daemon(1,1);

	shutdown_handler = [&exitFlag](int sig){ exitFlag = true; std::cout << "结束" << std::endl;};
	std::signal(SIGINT, signal_handler);

	char sendBuf[200];
	bzero(sendBuf,sizeof(sendBuf));
	strncpy(sendBuf, "Hi Client", sizeof(sendBuf) - 1);
	
	while(!exitFlag)
	{
		struct sockaddr_in addr;
		int ret = server->accept(&addr);
		if(ret >= 0)
		{
			/*
			 * newConn
			 */
			setNonBlocking(ret);
			TEMP_FAILURE_RETRY(::send(ret, sendBuf, sizeof(sendBuf), MSG_NOSIGNAL));
			TEMP_FAILURE_RETRY(::send(ret, sendBuf, sizeof(sendBuf), MSG_NOSIGNAL));
			TEMP_FAILURE_RETRY(::send(ret, sendBuf, sizeof(sendBuf), MSG_NOSIGNAL));
			TEMP_FAILURE_RETRY(::send(ret, sendBuf, sizeof(sendBuf), MSG_NOSIGNAL));
			std::cout << "收到客户端"<< std::endl;
		}
	}
	server->shutdown();
	
	return 0;
}
