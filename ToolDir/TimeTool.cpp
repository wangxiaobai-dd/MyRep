#include <iostream>
#include <time.h>
#include <string.h>
#include <unistd.h>

class TimeTool
{
	private:
		unsigned long long time = 0;
		static long timeZone;
		
	public:
		unsigned long long now()
		{
			unsigned long long nowMsec;
			struct timespec tv;
			clock_gettime(CLOCK_REALTIME, &tv);
			nowMsec = tv.tv_sec * 1000 + tv.tv_nsec / 1000000;
			return nowMsec;
		}
		
		void delay(int delay)
		{
			time = now();
			time += delay;	
		}

		unsigned long long elapse(const TimeTool& tt)
		{
			if(tt.time > time)
				return tt.time - time;
			else 
				return 0;
		}	

		static void setTimeZone()
		{
		 	tzset();
			timeZone = timezone;
		}

		static void getLocalTime(struct tm& tmt, time_t timeSec)
		{
			timeSec -= timeZone;
			gmtime_r(&timeSec, &tmt); // 线程安全 获取当前时间结构，UCT时间
		}

		static void getLocalTime2(struct tm& tmt, const time_t& timeSec)
		{
			localtime_r(&timeSec, &tmt); // 调用库函数
		}

		static std::string timeToStr(const time_t& t)
		{
			static char retStr[32];
			bzero(retStr, sizeof(retStr));
			struct tm tmt;
		//	TimeTool::getLocalTime(tmt, t);
			TimeTool::getLocalTime2(tmt, t);
			strftime(retStr, sizeof(retStr), "%Y年%m月%d日 %H:%M:%S", &tmt);
			return retStr;
		}

		static time_t mkTime(struct tm& tm)
		{
			return mktime(&tm); // UCT时间
		}
};

long TimeTool::timeZone = 0;

// timespec 纳秒
// timeval 微秒
struct BlockExecTime
{
	private:
		struct timespec tsp1;
		struct timespec tsp2;
		const uint64_t logInterval;
	public:
		BlockExecTime(const uint64_t interval): logInterval(interval)
		{
			clock_gettime(CLOCK_REALTIME, &tsp1);
		}
		~BlockExecTime(){}
		void elapse()
		{
			clock_gettime(CLOCK_REALTIME, &tsp2);
			uint64_t begin = tsp1.tv_sec * 1000 + tsp1.tv_nsec / 1000000;
			uint64_t end = tsp2.tv_sec * 1000 + tsp2.tv_nsec / 1000000;
			if(end - begin > logInterval)
			{
				std::cout << end - begin << std::endl;
			}
		}
};

int main()
{
	TimeTool::setTimeZone();
	auto ret = TimeTool::timeToStr(time(0));
	std::cout << ret << std::endl;

	BlockExecTime bet(3000);
	sleep(4);
	bet.elapse();
	
	return 0;
}
