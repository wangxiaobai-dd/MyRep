/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestSharedPtr.cpp
 * Author        : Meepo
 * Creation Date : 2022-05-20
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <map>

using namespace std;


struct A : public std::enable_shared_from_this<A>
{
	A(){ 
		cout << "construct : a" << endl; 
	}
	A(int a){ cout << "construct:aa" << endl; }
	virtual void call()
	{
		cout << "a" << endl;
	}
	virtual ~A()
	{
		cout << "~a" << endl;
	}
	const int bb = 1;

	virtual void test3(){ cout << "test3 A" << endl; }
};
std::vector<shared_ptr<A>> VVV;

struct B : public A
{
	//B(){ cout << "bb" << endl;}
	B(int a){ cout << "bbbb" << endl;}

	void call2(std::shared_ptr<A> aa)
	{
		VVV.push_back(aa);
	}
	void call()
	{
		call2(shared_from_this());
		//call2(std::shared_ptr<B>(this));
	}
	virtual ~B()
	{
		cout << "~b" << endl;
	}

	int a = 5;
	const int bb = 2;

	shared_ptr<B> getSharedFromThis() { return std::dynamic_pointer_cast<B>(shared_from_this()); }
	virtual void test3(){ cout << "test3 B" << endl; }
};

struct C: public B
{
	using B::B;
};


int main()
{
	/*
		shared_ptr<int> p = nullptr;
		vector<shared_ptr<int>> v;
		{
			p = make_shared<int>(1);
			auto& p1 = p;
			v.push_back(p1);
			v.push_back(p1);
			v.push_back(p1);
			v.push_back(p1);
		}
		std::array<shared_ptr<int>, 1> arr;
		std::map<int, shared_ptr<int>> mmap;
		if(!arr[0])
			cout << "empty" << endl;
		if(!mmap[0])
			cout << "empty2" << endl;
		arr[0] = p;
		std::fill(std::begin(arr), std::end(arr), nullptr);
		cout << p.use_count() << endl;

		for(auto iter = v.begin(); iter != v.end(); ++iter)
		{
			if(iter != --v.end())
				cout << "v" << endl;
		}
			
		auto& pp = mmap[0]; // 这里要引用
		if(!pp)
		{
			cout << "pp is null" << endl;
			pp = std::make_shared<int>();
			auto pp2 = mmap[0];
			if(pp2)
				cout << "pp2 is not null" << endl;
		}

		
		std::shared_ptr<A> ref2;


		{
		auto ref = std::make_shared<B>();
		//VVV.push_back(ref->shared_from_this());
		ref->call();
		cout << ref.use_count() << endl;
		//VVV.push_back(ref);

		cout << "==" << (ref == VVV[0]) << endl;

		//VVV.clear();
		//ref2 = ref;
		}
		cout << VVV[0].use_count() << endl;


		auto ppp = std::make_shared<B>();
		auto ppp2 = ppp;
		ppp = nullptr;
		if(ppp2)
			cout << ppp2->a << ":" << ppp2.use_count() << endl;

		*/

		map<int, std::shared_ptr<A>> smap;
		smap[1] = std::make_shared<B>(1);
		auto& a = smap[1];  
		//cout << a->bb << endl;
		std::shared_ptr<B> bb = std::dynamic_pointer_cast<B>(a);
		//aa = std::make_shared<B>(1);
		if(!a)
		{
			cout << "no a "<< endl;
		}
		if(!bb)
		{
			cout << "no bb "<< endl;
		}
		else
			cout << "has bb" << endl;

		C* c = new C(1);
		c->test3();

		while(true);

		//cout << ref2.use_count() << endl;
		//ref->call();
		
	return 0;
}

