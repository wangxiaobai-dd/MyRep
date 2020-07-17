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

int main()
{
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

	return 0;
}
