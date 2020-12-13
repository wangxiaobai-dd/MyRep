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

struct C
{
	~C(){ cout << "~~c" << endl;}
};
struct B
{
	C* c = nullptr;
	~B(){ cout << "~~b " << endl;}
};

struct D
{
	D(){}
	D(const D& rhs){ cout << "lhs copy" << endl;}
	D(const D&& rhs){ cout << "rhs copy" << endl;}
};


int main()
{

	/*
	std::map<int, int*> testMap;
	testMap[1] = new int();
	testMap[2] = new int();
	testMap[3] = new int();
	//A::del();
	//
	for(auto iter = testMap.begin(); iter != testMap.end(); ++iter)
		delete iter->second;

	std::vector<int*> testVec;
	testVec.push_back(new int);
	testVec.push_back(new int);
	testVec.push_back(new int);

	for(auto iter = testVec.begin(); iter != testVec.end(); ++iter)
		delete *iter;
	
	std::set<int*> testSet;
	testSet.insert(new int);
	testSet.insert(new int(2));
	testSet.insert(new int(3));

	for(auto iter = testSet.begin(); iter != testSet.end(); ++iter)
		delete *iter;

	std::cout << testSet.size()  << std::endl;	
	std::cout << "1" << std::endl;	
	std::cout << "1" << std::endl;	

	vector<int> vn{ 1, 2, 3};
	for (auto&& value : vn) {    cout << typeid(value).name() << endl;  }
	for (auto& value : vn) {    cout << typeid(value).name() << endl;  }
	*/

	int* myA = new int(100);
	int* myB = new int(90);
	int* myC = new int(80);

	cout << myA << endl;
	cout << myB << endl;
	cout << myC << endl;
	map<int, map<int, B*>*  > mMap;
	mMap[1] = new map<int, B*>;
	mMap[2] = new map<int, B*>;

	/*
	B* a = new B();
	a->myInt = myA;
	B* b = new B();
	b->myInt = myB;
	B* c = new B();
	c->myInt = myC;

	(*mMap[1])[1] = a;
	(*mMap[1])[2] = b;
	(*mMap[2])[1] = c;
	// cout << *b->myInt << endl;
	B* d = new B();
	d->myInt = new int(500);
	(*mMap[1])[1] = d;
	*/

	/*
	for(auto iter = mMap.begin(); iter != mMap.end(); ++iter)
	{
		for(auto mIter = iter->second->begin(); mIter != iter->second->end(); ++mIter)
			delete mIter->second;
		std::cout << "first:" << iter->first << endl;
		delete iter->second;
	}
	*/

	cout << myA << endl;
	cout << myB << endl;
	cout << myC << endl;

	cout << *myA << endl;
	cout << *myB << endl;
	cout << *myC << endl;

	std::map<int, B> mmmMap;
	{
		B b;
		b.c = new C();
		mmmMap[1] = b;
	}
	// getchar();
	{
		B b;
		b.c = new C();
		mmmMap.erase(1);
		getchar();
		mmmMap[1] = b;
	}

	D d;
	D d1(std::move(d));

	getchar();
	
	return 0;
}
