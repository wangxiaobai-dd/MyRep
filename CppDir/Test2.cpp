#include <string>
#include "stdio.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
 
#define OUT_IN_REPEATE_NUM 10000
#define IN_REPEATE_NUM 6000000

string s1 = "喝喝";
string s2 = "中立区";
string s3 = "opqrst";
void  plusTest()
{
	string ret;
	for (int i = 0; i<IN_REPEATE_NUM; i++)
	{
		ret += s1;
		ret += s2;
	}
}
void  appendTest()
{
	string ret;
	for (int i = 0; i<IN_REPEATE_NUM; i++)
	{
		ret.append(s1);
		ret.append(s2);
	}
}
void sprintfTest()
{
	for (int i = 0; i< IN_REPEATE_NUM; i++)
	{
		char str[80000];
		sprintf(str, "%s%s%u", "abcedfg","hijklmn", 11);
	}
}

void  ssTest()
{
	stringstream ss;
	for (int i = 0; i<IN_REPEATE_NUM; i++)
	{
		ss << s1;
		ss << s2;
	}
}

/**函数调用用时*/
auto timeFunInvocation = [](auto&& func, auto&&... params)
{
	clock_t t1 = clock();
	std::forward<decltype(func)>(func)(std::forward<decltype(params)>(params)...);
	cout << (clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000 << endl;
};

template <class T>
void printarg(T t)
{
	cout << t << endl;
}

/**变长参数展开*/
template<class F, class... Args> void expand(const F& f, Args&&...args)
{
	initializer_list<int>{(f(std::forward<Args>(args)), 0)...};
}

template <typename U>
static char ArenaConstructable(const typename U::InternalArenaConstructable_*);

template <typename U>
static char ArenaConstructable(...);

struct A
{
	int a;
	char b[10] = {"hehe"};
};

void fun(A* i){
	cout << i->a << " ";
}

int main()
{
	/*
	// 1.函数调用计时
	timeFunInvocation(plusTest);
	timeFunInvocation(appendTest);
	timeFunInvocation(sprintfTest);
	timeFunInvocation(ssTest);
	
	// 2.变长参数展开
	expand([](int i) {cout << i << endl; }, 1, 2, 3);
	*/
	
	// T, T val 模板元编程
	typedef std::integral_constant<int, 2> two_t;
	typedef std::integral_constant<int, 4> four_t;
	static_assert(two_t::value * 2 == four_t::value, "2*2 != 4");

	auto v = static_cast<A*>(0);
	std::cout << v << std::endl;

	size_t n = 7;
	std::cout << ((n + 7) & static_cast<size_t>(-8)) << std::endl;

	std::ostringstream str;
//	unsigned char a = 48;
//	str << a << "值";
	printf("%s\n", str.str().c_str());

	char buf[20] = {0};
	A *send = (A*)buf;
	new (send)A();
	std::cout << "size" << sizeof(*send) << std::endl;
	std::cout << "size" << sizeof(A) << std::endl;


	std::string config = "1-2";
	unsigned int a[3] = {0};

	sscanf(config.c_str(), "%u-%u-%u", &a[0], &a[1], &a[2]);
	std::cout << a[0] << std::endl;
	std::cout << a[1] << std::endl;
	std::cout << a[2] << std::endl;

	A aaa;
	strncpy(aaa.b, "haha", 10);
	std::cout << aaa.b << std::endl;
	A bbb;
	bbb = aaa;
	strncpy(aaa.b, "dede", 10);
	std::cout << bbb.b << std::endl;
	std::cout << aaa.b << std::endl;

	std::set<int> sss1;
	std::set<int> sss2;
	for(int i = 1; i <= 1000; ++i)
	{
		sss2.insert(i);
	}

	int place = 0;
	int aim = 1001;
	auto func = [&place, &aim](const auto& t)
	{
		++place;
		return t == aim;
	};
	auto iter = std::find_if(sss2.begin(), sss2.end(), func);
	if(iter == sss2.end())
		std::cout << "no" << std::endl;
	std::cout << place << std::endl;
}
	     
