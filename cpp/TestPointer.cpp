/* 
 * Copyright (C) 2023 Meepo All Rights Reserved.
 * 
 * File Name     : TestPointer.cpp
 * Author        : Meepo
 * Creation Date : 2023-05-18
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <set>

using namespace std;

struct A 
{
	void test()
	{
		if(!a)
			a = new int(2);
	}
	void test2()
	{
		if(a)
		{
			cout << "test2" << endl;
			cout << *a << endl;
		}
	}
	int* a = nullptr;
};

int main()
{
	A sa;
	sa.test();
	int* &b = sa.a;// 需要引用
	cout << *b << endl;
	delete b;
	b = nullptr;
	sa.test2();

	std::set<int> s;


	while(1);
	return 0;
}

