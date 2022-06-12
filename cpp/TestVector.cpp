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

using namespace std;

int main()
{
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
	return 0;
}

