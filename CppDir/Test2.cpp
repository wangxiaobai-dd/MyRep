#include <string>
#include "stdio.h"
#include <iostream>
#include <sstream>
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

int main()
{
	// 1.函数调用计时
	timeFunInvocation(plusTest);
	timeFunInvocation(appendTest);
	timeFunInvocation(sprintfTest);
	timeFunInvocation(ssTest);
	
	// 2.变长参数展开
	expand([](int i) {cout << i << endl; }, 1, 2, 3);
	
}
	     
