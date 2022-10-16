/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestTypedef.cpp
 * Author        : Meepo
 * Creation Date : 2022-06-12
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template <typename T>
void destructor(void* obj)
{
	typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
	T_must_be_complete_type dummy; 
	//(void) dummy;
	cout << typeid(T_must_be_complete_type).name() << endl;
	cout << sizeof(T_must_be_complete_type) << endl;
	cout << dummy << endl;
	char bb;
	(void)bb;
}

int main()
{
	destructor<int>(new int);
	return 0;
}

