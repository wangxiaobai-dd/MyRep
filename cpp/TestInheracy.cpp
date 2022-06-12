/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestInheracy.cpp
 * Author        : Meepo
 * Creation Date : 2022-05-25
 * INFO          :
 *
 */


#include <iostream>
#include <string>

using namespace std;

struct A
{
	virtual void test2(){ cout << "A" << endl;}
	virtual void test3(){};
	virtual void test6(){};
	virtual void test7(){};
	virtual void test8(){};
	virtual void test9(){};
	virtual void test(){ cout << "A" << endl;}
	void test4(){ cout << "A" << endl;};
};
struct B : public A
{
	int C;
	int B;
	int D;
	virtual void test3(){};
	virtual void test(){ cout << "B" << endl;}
	virtual void test6(){};
	virtual void test7(){};
	virtual void test8(){};
	virtual void test9(){};
	void test4(){ cout << "B" << endl;};
};
struct C : public A
{
	int C;
	virtual void test6(){};
	virtual void test7(){};
	virtual void test8(){};
	virtual void test1(){};
	virtual void test2(){ cout << "C" << endl;}
	virtual void test(){ cout << "C" << endl;}
	virtual void test3(){ cout << "C" << endl;}
	void test4(){ cout << "C" << endl;};
};

int main()
{
	A* obj = new B();
	((C*)obj)->test();
	((C*)obj)->test4();
	
	return 0;
}

