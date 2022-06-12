/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestSharedPtr.cpp
 * Author        : Meepo
 * Creation Date : 2022-05-20
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
		shared_ptr<int> p = nullptr;
		vector<shared_ptr<int>> v;
		{
			p = make_shared<int>(1);
			auto& p1 = p;
			v.push_back(p1);
			v.push_back(p1);
			v.push_back(p1);
			v.push_back(p1);
		}
		std::array<shared_ptr<int>, 1> arr;
		std::map<int, shared_ptr<int>> mmap;
		if(!arr[0])
			cout << "empty" << endl;
		if(!mmap[0])
			cout << "empty2" << endl;
		arr[0] = p;
		std::fill(std::begin(arr), std::end(arr), nullptr);
		cout << p.use_count() << endl;

		for(auto iter = v.begin(); iter != v.end(); ++iter)
		{
			if(iter != --v.end())
				cout << "v" << endl;
		}
			
		
	return 0;
}

