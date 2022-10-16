/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : BitMove.cpp
 * Author        : Meepo
 * Creation Date : 2022-09-19
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
	std::string bit_string;
	std::bitset<42> num(-1);
	std::cout << num.to_ulong() << std::endl;
	return 0;
}

