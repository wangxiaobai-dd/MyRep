#ifndef NF_USER_H
#define NF_USER_H
#include <set>
struct User
{
	int a = 0;
	std::set<int> s;
	static int b;
	static void test(){}
};
#endif
