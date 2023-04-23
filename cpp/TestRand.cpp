/* 
 * Copyright (C) 2023 Meepo All Rights Reserved.
 * 
 * File Name     : TestRand.cpp
 * Author        : Meepo
 * Creation Date : 2023-01-10
 * INFO          :
 *
 */



#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <vector>
#include <unistd.h>

int main()
{
	while(true)
	{
		std::vector<int> vec{1, 2, 3};

		std::mt19937 gen(std::random_device{}());
		std::shuffle(vec.begin(), vec.end(), gen);

		std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

		std::cout << std::endl;
		sleep(1);
	}

	return 0;
}



