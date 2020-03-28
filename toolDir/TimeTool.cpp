#include <iostream>
#include <time.h>
#include <string.h>

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
			gmtime_r(&timeSec, &tmt); // �̰߳�ȫ ��ȡ��ǰʱ��ṹ��UCTʱ��
		}

		static void getLocalTime2(struct tm& tmt, const time_t& timeSec)
		{
			localtime_r(&timeSec, &tmt); // ���ÿ⺯��
		}

		static std::string timeToStr(const time_t& t)
		{
			static char retStr[32];
			bzero(retStr, sizeof(retStr));
			struct tm tmt;
		//	TimeTool::getLocalTime(tmt, t);
			TimeTool::getLocalTime2(tmt, t);
			strftime(retStr, sizeof(retStr), "%Y��%m��%d�� %H:%M:%S", &tmt);
			return retStr;
		}

		static time_t mkTime(struct tm& tm)
		{
			return mktime(&tm); // UCTʱ��
		}
};

long TimeTool::timeZone = 0;


int main()
{
	TimeTool::setTimeZone();
	auto ret = TimeTool::timeToStr(time(0));
	std::cout << ret << std::endl;
	
	return 0;
}
