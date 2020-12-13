#include <iostream>
#include <string>
#include <hiredis/hiredis.h>
#include <time.h>
#include <unistd.h>

#include "message.pb.h"
/**
#define REDIS_REPLY_STRING 1    //字符串
#define REDIS_REPLY_ARRAY 2     //数组，例如mget返回值
#define REDIS_REPLY_INTEGER 3   //数字类型
#define REDIS_REPLY_NIL 4       //空
#define REDIS_REPLY_STATUS 5    //状态，例如set成功返回的‘OK’
#define REDIS_REPLY_ERROR 6     //执行失败
*/
void command(redisContext* context, const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	redisReply* reply = (redisReply*)redisvCommand(context, format, ap);
	if(reply && reply->type == REDIS_REPLY_INTEGER)
		std::cout << "command int result: " << reply->integer << std::endl;
	if(reply && (reply->type == REDIS_REPLY_STRING || reply->type == REDIS_REPLY_ERROR || reply->type == REDIS_REPLY_STATUS))
	{
		// std::cout << "command str result: " << reply->str << std::endl;
		// 怎样区分protobuf
		test::User u2;
		u2.ParseFromArray(reply->str, reply->len);
		std::cout << u2.id() << std::endl;
		std::cout << u2.username() << std::endl;
	}
	va_end(ap);
	freeReplyObject(reply);
}

void commandPip(redisContext* context, const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	int ret = redisvAppendCommand(context, format, ap);
	va_end(ap);
	std::cout << "command pip ret:" << ret << std::endl;
}

void getReplyPip(redisContext* context)
{
	redisReply* reply;
	int ret = redisGetReply(context, (void**)&reply);
	if(reply && reply->type == REDIS_REPLY_INTEGER)
		std::cout << "reply pip resultInt: " << reply->integer << std::endl;
	if(reply && (reply->type == REDIS_REPLY_STRING || reply->type == REDIS_REPLY_ERROR || reply->type == REDIS_REPLY_STATUS))
		std::cout << "reply pip resultStr: " << reply->str << std::endl;
	freeReplyObject(reply);
	// std::cout << "reply pip ret:" << ret << std::endl;
}

/*
 * 同步redis
 */
int main(int agrc, char** argv)
{
	// redisContext* context = redisConnect("127.0.0.1", 6380);
	struct timeval timeout;
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;
	redisContext* context = redisConnectWithTimeout("127.0.0.1", 6380, timeout);
	if(context == nullptr)
	{
		std::cout << "connect redis failed" << std::endl;
		exit(-1);
	}
	if(context->err)
	{
		std::cout << "connect error" << context->errstr << std::endl;
		redisFree(context);
		context = nullptr;	
	}
	
	// select 0
	auto* reply0 = (redisReply*)redisCommand(context, "SELECT %d", 0);	
	if(reply0)
	{
		std::cout << "select ret:" << reply0->str << std::endl;
	}
	
	std::string key = "name";
	std::string value = "white";

	// set
	/*redisCommand(context, "SET %s %s", key.c_str(), value.c_str());	

	// get
	redisReply* reply = (redisReply*)redisCommand(context, "GET %s", key.c_str());
	if(reply && reply->str)
	{
		std::string ret = reply->str;
		std::cout << "value: " << ret << std::endl;
		freeReplyObject(reply);
	}
	*/

	// pipline
	//commandPip(context, "INCRBY counter 50");
	//getReplyPip(context);

	test::User u;
	u.set_id(1);
	u.set_username("white");
	const int byteSize = u.ByteSizeLong();
	char buf[byteSize];
	bzero(buf, byteSize);
	u.SerializeToArray(buf, byteSize);
	command(context, "SET %b %b", u.username().c_str(), (int)u.username().length(), buf, byteSize);
	command(context, "GET white");

	// sub
	// command(context, "SUBSCRIBE %b", "chat", 4);
	// pub 
	//command(context, "PUBLISH %b %b", "chat", 4, "test", 4);

	redisFree(context);
	return 0;
}
