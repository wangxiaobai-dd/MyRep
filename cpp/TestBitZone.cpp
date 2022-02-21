#include <iostream>
#include <string>

using namespace std;

#pragma pack(1)
typedef struct redisObject {
	unsigned type:4; //redisObject的数据类型，4个bits
	unsigned encoding:4; //redisObject的编码类型，4个bits
	//int refcount; //redisObject的引用计数，4个字节
} robj;
#pragma pack()

int main()
{
	std::cout << sizeof(robj) << std::endl;
	return 0;
}

