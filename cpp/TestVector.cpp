/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestVector.cpp
 * Author        : Meepo
 * Creation Date : 2022-05-16
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>

using namespace std;

struct B
{
	struct A
	{
		std::vector<int> v;
	}Aa;
	~B(){ std::cout << "~b" << std::endl;}
};


int main()
{
	//B Bb;
	//std::cout << Bb.Aa.v.size() << std::endl;
	vector<int> a(10);
	//a.resize(2);
	//a.resize(1);
	//a.reserve(10);
	a[0] = 1;
	a[1] = 2;
	a[2] = 2;
	a[3] = 2;
	a[4] = 2;
	a.resize(2);
	// wrong
	cout << a.capacity() << endl;
	cout << a.size() << endl;
	for(auto num : a)
		cout << num << endl;

	cout << "usecount" << endl;
	vector<shared_ptr<int>> b;
	shared_ptr<int> s1 = shared_ptr<int>(new int);
	shared_ptr<int> s2 = shared_ptr<int>(new int);
	b.push_back(s1);
	b.push_back(s2);
	cout << s2.use_count() << endl;
	b.resize(1);
	cout << s2.use_count() << endl;

	int aa[3];
	cout << sizeof(aa) << endl;

	std::list<B*> bVec;
	B* bb1 = new B();
	bVec.push_back(bb1);
	bVec.erase(bVec.begin());
	//delete(bb1);
	//
	int aint = 0;
	unsigned int bint = 1;
	aint = aint - bint;
	cout << aint << endl;

	string str;
	str.starts_with("");
	while(true);
	
	return 0;
}

