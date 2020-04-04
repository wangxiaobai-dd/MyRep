#include <iostream>
#include <string>
#include <queue>
#include <hiredis/hiredis.h>
#include <time.h>
#include <unistd.h>
#include <ev.h>
#include <hiredis/async.h>
#include <hiredis/adapters/libev.h>

#include "EventLoop.h"

static void asyncCallback(redisAsyncContext* c, void* r, void* privdata)
{
	if(r)
	{
		redisReply* reply = (redisReply*)r;
		if(reply && reply->type == REDIS_REPLY_INTEGER)
			std::cout << "asyn command result: " << reply->integer << std::endl;
		if(reply && (reply->type == REDIS_REPLY_STRING || reply->type == REDIS_REPLY_ERROR || reply->type == REDIS_REPLY_STATUS))
			std::cout << "asyn command result: " << reply->str << std::endl;
	}
	std::cout << "asyncCallback" << std::endl;
}
void command(redisAsyncContext* context, const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	redisvAsyncCommand(context, asyncCallback, nullptr, format, ap);
	va_end(ap);
}

struct EventRunner : TimerEvent
{
	public:
		void called() override
		{
			if(!cmdQueue.empty())
			{
				command(_context, cmdQueue.front().c_str());
				cmdQueue.pop();
			}
		}
		// 简化一层调度器 直接写个队列 线程不安全
		std::queue<std::string> cmdQueue;
		redisAsyncContext* _context;
};

int main(int agrc, char** argv)
{

	// evloop	
	// struct ev_loop* evLoop = ev_default_loop(0);	
	// evLoop = ev_loop_new(EVFLAG_AUTO);
	EventRunner event;
	EventLoop::instance()->regTimer(&event, 2, 0);	

	redisAsyncContext* context = redisAsyncConnect("127.0.0.1", 6380);
	if(context == nullptr)
		return 0;
	if(context->err)
	{
		std::cout << "connect error" << std::endl;
		redisAsyncDisconnect(context);
		return 0;
	}
	event._context = context;

	redisLibevAttach(EventLoop::instance()->evLoop, context);
	redisAsyncSetConnectCallback(context, [](const redisAsyncContext* c, int status){ if(status == REDIS_OK)
			std::cout << "connect success " << std::endl;});
	redisAsyncSetDisconnectCallback(context, [](const redisAsyncContext* c, int status){ if(status == REDIS_OK)
			std::cout << "disconnect success" << std::endl;});

	std::string key = "asynckey";
	std::string value = "asyncvalue";
	std::string cmd1 = "SET " + key + " " + value;
	std::string cmd2 = "GET " + key;

	event.cmdQueue.push(cmd1);
	event.cmdQueue.push(cmd2);

	EventLoop::instance()->loop();


	redisAsyncDisconnect(context);
	return 0;
}
