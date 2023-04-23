/* 
 * Copyright (C) 2023 Meepo All Rights Reserved.
 * 
 * File Name     : TestMemoryCopy.cpp
 * Author        : Meepo
 * Creation Date : 2023-02-09
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct C{

	int c = 1;

};

#pragma pack(1)

struct A : public C
{
	int a = 4;
	int b = 5;
	int getSize(){ return (sizeof(a) + sizeof(b)); };
};

struct AB : public A
{
	char a = 4;
	short b = 5;
	int getSize(){ return (sizeof(a) + sizeof(b)); };
};

#pragma pack()


int main()
{
	char msg[1000];
	{
		struct A aa;
		memmove(msg, (char*)&aa, sizeof(aa));
	}
	std::cout << ((A*)msg)->a << ((A*)msg)->b << std::endl;

	AB *ab = new AB();
	cout << ((A*)(ab))->getSize() << endl;
	return 0;
}

