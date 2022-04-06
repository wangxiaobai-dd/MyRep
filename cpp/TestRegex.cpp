/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestRegex.cpp
 * Author        : Meepo
 * Creation Date : 2022-03-22
 * INFO          :
 *
 */

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string str1 = R"(#include "u1.cpp")";
	//cout << str1 << endl;
	regex reg2{"\""};
	std::sregex_token_iterator pos(str1.begin(), str1.end(), reg2, -1);
	decltype(pos) end;
	//cout << (++pos)->str() << endl;
	for (; pos != end; ++pos)
	{
			//std::cout << pos->str() << std::endl;
	}

	std::cmatch m;
//	auto ret = std::regex_match("<xml>value</xml>", m, std::regex(".*\"(.*)\""));
	auto ret = std::regex_match(str1.c_str(), m, std::regex(".*\"(.*)\""));
	if (ret)
	{
		std::cout << m.str() << std::endl;
		std::cout << m.length() << std::endl;
		std::cout << m.position() << std::endl;
	}
	for (auto i = 0; i < m.size(); ++i)
	{
		// 两种方式都可以
		std::cout << m[i].str() << " " << m.str(i) << std::endl;
	}
	return 0;
}

