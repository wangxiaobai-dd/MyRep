#include <iostream>
#include <time.h>
#include <string.h>
#include <unistd.h>


// timespec ƒ…√Î
// timeval Œ¢√Î
// output:∫¡√Î
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
		~BlockExecTime()
		{
			clock_gettime(CLOCK_REALTIME, &tsp2);
			uint64_t begin = tsp1.tv_sec * 1000 + tsp1.tv_nsec / 1000000;
			uint64_t end = tsp2.tv_sec * 1000 + tsp2.tv_nsec / 1000000;
			std::cout << end - begin << std::endl;
		}
};

