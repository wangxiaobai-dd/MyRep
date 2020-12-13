//#include <type_traits> 
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <functional>
//#include "nv.h"
#include <tuple>
#include <string>
#include <memory>
#include <pthread.h>
#include <thread>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
using namespace std;

using BYTE = unsigned char;
enum class TEST : unsigned short
{
	ONE = 63,
	MAX
};

int main()
{
	//int a = static_cast<unsigned short>(TEST::ONE);
	if(TEST::ONE < TEST::MAX)
		std::cout << 100 << std::endl;
	if(static_cast<TEST>(63) == TEST::ONE)
		std::cout << 200 << std::endl;
	return 0;
}
