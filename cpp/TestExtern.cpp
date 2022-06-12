#include <iostream>
#include <string>
#include "TestStatic1.h"

namespace ser{

	// 如果声明在头文件中 则不需要
	//extern A* aa;
}

int main()
{
	//aa.test();
	ser::init();
	std::cout << ser::aa->a << std::endl;
	return 0;
}

