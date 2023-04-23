/* 
 * Copyright (C) 2023 Meepo All Rights Reserved.
 * 
 * File Name     : TestUnsigned.cpp
 * Author        : Meepo
 * Creation Date : 2023-04-07
 * INFO          :
 *
 */


#include <iostream>
#include <string>

using namespace std;

void test(int a)
{
	cout << a << endl;
}

int main()
{
	unsigned int a = 100;
	unsigned int b = 120;
	test(a - b);
	return 0;
}

