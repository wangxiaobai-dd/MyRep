/* 
 * Copyright (C) 2023 Meepo All Rights Reserved.
 * 
 * File Name     : TestOverride.cpp
 * Author        : Meepo
 * Creation Date : 2023-04-14
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <iterator>

using namespace std;


class Person
{
public:
	virtual void eat() const = 0;               // 1.纯虚函数
	virtual void say(const std::string& msg){};   // 2.普通虚函数
	int name() const;                           // 3.非虚函数
};

class Student : public Person
{
public:
protected:
private:
};

class Teacher : public Student
{
public:
	virtual void eat() const override{};
protected:
private:
};

template <class T, size_t N>
void test(T (&array)[N])
{
	std::begin(array);
}
// 不能传数组参数

int main()
{
	Teacher t[3];
	test(t);

	int arr[12];
	cout << sizeof(arr) << endl;

	struct 
	{
		unsigned char c = 0;
		int a = 0;
		int b = 0;
	}aaa;

	aaa = {4, 1, 1};
	cout << aaa.c << endl;
	
	return 0;
}

