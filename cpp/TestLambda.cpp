//#include <type_traits> 
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <functional>
//#include "nv.h"
#include <tuple>
#include <string>
#include <memory>
#include <pthread.h>
#include <thread>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
// ÕûÊý¡¢×Ö·û´®¡¢×Ö·û´®µÄÈýÔª×é
using namespace std;
using num_tuple = tuple<int, string, string>;

void test(std::function<void(int)>&& f)
{
	std::function<void(int)> tmp(f);
	tmp(1);
}

ostream&operator<<(ostream& os,           const num_tuple& value){  os << get<0>(value) << ','     << get<1>(value) << ','     << get<2>(value);  return os;}

struct A
{
	static A* ins;
	A()
	{
	}
	static A* get()
	{
		if(!ins)
			ins = new A();
	}
	~A()
	{
		std::cout << "delete" << std::endl;
	}
	static void destroy()
	{
		if(ins)
			delete ins;
	}
};
A* A::ins = nullptr;

struct B
{
	int* myInt = nullptr;
	~B()
	{ 
		cout << "~~b " << endl;
	}
};

struct C
{
	int a = 1;	
	map<int, map<int, B*>*  > mMap;
	~C()
	{
		cout << "~~c " << endl;
		/*
		for(auto iter = mMap.begin(); iter != mMap.end(); ++iter)
		{
			for(auto mIter = iter->second->begin(); mIter != iter->second->end(); ++mIter)
				delete mIter->second;
			delete iter->second;
		}
		*/
	}
};

std::shared_ptr<C> init()
{
    auto p = std::make_shared<C>();
    std::cout << "init" << p.use_count() << std::endl;
    return p;
}

std::unique_ptr<C> initU()
{
    auto p = std::make_unique<C>();
    return p;
}

void testInitU(const std::shared_ptr<C>& pu)
{
    std::cout << "testUI before : " << pu->a << std::endl; 
    auto p = pu;
    std::cout << "testIU: " << p.use_count() << std::endl;
}

void test(int*& a)
{
    a = nullptr;
}

void testCallback(const std::function<void(void)>& exec)
{
    exec();
}

int main()
{
    /*
	int* ia = new int(100);
	std::map<int, C> cMap;
	{
		C c;
		c.mMap[1] = new map<int, B*>;
		c.mMap[2] = new map<int, B*>;

		B* b = new B();
		b->myInt = ia;
		(*c.mMap[1])[1] = b;

		cMap[1] = c;
	}
	cout << *(*cMap[1].mMap[1])[1]->myInt << endl;
//	delete ia;
	//cout << *ia << endl;
	getchar();
	int *a = new int();
	*/
	std::vector<std::shared_ptr<C>> vec;
	auto pc = init();
	vec.push_back(pc);
	std::cout << "after push " << pc.use_count() << std::endl;
	vec.clear();
	std::cout << "after clear" << pc.use_count() << std::endl;

	testInitU(pc);

	std::vector<int> v1 = {1,2,3};
	std::vector<int> v2;
	v2.reserve(3);
	v2.assign(v1.begin(), v1.end());

	int* a = new int;
	test(a);
	if(a)
	{
	    std::cout << "aaaaaaaaaaa" << std::endl;
	}

	auto comp = [](auto a, auto b){ return a.second.second < b.second.second; };
	std::unordered_map<int, std::pair<int, int>> tm;
	tm[0] = {0,1};
	tm[1] = {0,3};
	tm[2] = {0,2};
	auto maxIter = std::max_element(tm.begin(), tm.end(), comp);
	std::cout << "max" << maxIter->first << std::endl;

	int aaa = 3;
	const auto callback = [&aaa](){ std::cout << "callback" << aaa << std::endl;};

	testCallback(callback);
	aaa = 4;
	testCallback(callback);
	
	return 0;
}

