#pragma once
#include <iostream>

namespace ser{

	void init();

	class A
	{
		public:
			A(){
				std::cout << "A" << std::endl;
			}
			A(int _a) : a(_a){}
			void test();
			int a = 3;
	};

	extern A* aa;


}
