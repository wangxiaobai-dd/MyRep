/* 
 * Copyright (C) 2023 Meepo All Rights Reserved.
 * 
 * File Name     : TestTruncation.cpp
 * Author        : Meepo
 * Creation Date : 2023-01-10
 * INFO          :
 *
 */


#include <iostream>
#include <string>

struct A 
{
	int a = 100;
	char b = 'b';
};

struct B : A{
	int name[3] = {100, 100, 100};
};

struct C{};

using namespace std;

int main()
{
	B b;
	A a = b;
	cout << a.a << a.b << endl;
	return 0;
}


