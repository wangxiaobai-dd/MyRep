#include <iostream>
class A
{
	public:
	A(){
		std::cout << "A" << std::endl;
	}
	void test(){};
	int a = 3;
};

extern A aa;
