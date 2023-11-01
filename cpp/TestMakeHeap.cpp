/* 
 * Copyright (C) 2023 Meepo All Rights Reserved.
 * 
 * File Name     : TestMakeHeap.cpp
 * Author        : Meepo
 * Creation Date : 2023-04-11
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string_view>
#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
 

using namespace std;

void print(std::string_view text, std::vector<int> const& v = {})
{
	    std::cout << text << ": ";
		    for (const auto& e : v) std::cout << e << ' ';
			    std::cout << '\n';
}

const int n_operations = 100500;

std::vector<int> v {3, 2, 4, 1, 5, 9, 10, 11, 8, 7};
std::vector<int> v2 {11,8,10,3,7,9,4,1,2,5};
//11 8 10 3 7 9 4 1 2 5
std::set<int> s{3, 2, 4, 1, 5, 9, 10, 11, 8, 7};
 
void make_one() {
	for(int i = 0; i < n_operations; ++i) {
		auto tmpv = v;
		std::make_heap(v.begin(), v.end());
	}
}
void make_two() {
	for(int i = 0; i < n_operations; ++i) {
		//auto tmpv = v2;
		std::make_heap(v2.begin(), v2.end());
	}
}
void make_three()
{
	int n = 3;
	for(int i = 0; i < n_operations; ++i) {
	//	auto tmps = s;
		s.erase(n);
		if(n == 3)
			n = 30;
		else 
			n = 3;
		s.insert(n);

		/*
		auto nh = s.extract(n);
		if(!nh.empty())
		{
			if(n == 3)
				n = 30;
			else 
				n = 3;
			nh.value() = n;
			s.insert(std::move(nh));
		}
		*/
	}
}
void make_four()
{
	for(int i = 0; i < n_operations; ++i) {
		//auto tmps = s;
	}
}

void timeit(std::function<void()> set_test, const char* what = nullptr) {
	const auto start = std::chrono::system_clock::now();
	set_test();
	const auto stop = std::chrono::system_clock::now();
	const std::chrono::duration<double, std::milli> time = stop - start;
	if (what != nullptr) {
		std::cout << std::setw(6) << time.count() << "  ms for " << what << '\n';
	}
}

int main()
{
	/*
	std::vector<int> v1 {3, 2, 4, 1, 5, 9};
	std::make_heap(v1.begin(), v1.end(), std::greater<>{});
	print("greater:", v1);
	std::make_heap(v1.begin(), v1.end(), std::less<>{});
	v1[0] = 2;
	std::make_heap(v1.begin(), v1.end(), std::less<>{});
	print("less:", v1);

	int arr[3];
	for(const auto i : arr)
		cout << i << endl;
	*/

	std::make_heap(v.begin(), v.end());
	print("make", v);


	int v2[] = {1,2,3,4,5};
	auto iter =adjacent_find(std::begin(v2), std::end(v2), [](const int a, const int b) {
			return (a + 1 != b);
			});
	cout << "adjacent_find:" << (iter == std::end(v2)) << endl;

	
	// test make heap

	std::cout << std::fixed << std::setprecision(2);
	timeit(make_one, "make_heap");
	timeit(make_two, "make_heap2");
	timeit(make_three, "make_heap3");
	timeit(make_four, "make_heap4");


	return 0;
}

