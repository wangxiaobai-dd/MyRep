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

using namespace std;

void print(std::string_view text, std::vector<int> const& v = {})
{
	    std::cout << text << ": ";
		    for (const auto& e : v) std::cout << e << ' ';
			    std::cout << '\n';
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


	int v2[] = {1,2,3,4,5};
	auto iter =adjacent_find(std::begin(v2), std::end(v2), [](const int a, const int b) {
			return (a + 1 != b);
			});
	cout << (iter == std::end(v2)) << endl;


	return 0;
}

