/* 
 * Copyright (C) 2023 Meepo All Rights Reserved.
 * 
 * File Name     : TestConstruct.cpp
 * Author        : Meepo
 * Creation Date : 2023-04-20
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <map>

using namespace std;

template <int N>
struct A
{
	A(int _a)
	{
		a = _a;
		cout <<"c" << endl;
	}
	A(){
		cout << N << endl;
	
	}
	A& operator = (const A&a)
	{
		cout << "ccc"<<endl;
		return *this;
	}
	A(const A& _a)
	{
		a = _a.a;
		cout <<"cc" << endl;
		cout <<"cc" << endl;
	}
	int a = 0;
};

template <int M>
struct B : public A<M>
{
	B()
	{
		cout << M << endl;
	}

};

int main()
{
	//A<1> a;
	B<3> b;

	std::map<int, int> mapp;
	cout << sizeof(mapp) << endl;

	while(true);
	return 0;
}

