#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <typeinfo>
#include <map>
#include <vector>
#include <memory>
using namespace std;
 
struct sortSt
{
	public:
	int index = 0;

	// 相同对象不能返回true
	bool operator < (const sortSt& info) const
	{
		return this->index < info.index;
		//return false;
	}
	/*friend bool operator < (const sortSt& lhs, const sortSt& rhs)
	{
		return lhs.index < rhs.index;
	}
	*/
};

struct event
{
	int time = 0;
	int tableID = 0;
};

struct com
{
	bool operator ()(const std::shared_ptr<event> e1, const std::shared_ptr<event> e2) const
	{
		if(e1->time != e2->time)
			return e1->time < e2->time;
		return e1->tableID < e2->tableID;
	}
};

int main()
{
	//std::set<int> coll;
	/*std::map<int, int> coll;
	coll.insert({1,1});
	const auto& collcopy = coll;
	auto iter1 = coll.begin();
	auto iter = collcopy.begin();
	std::advance(iter, 1);
	std::cout << typeid(iter1).name() << std::endl;
	std::cout << typeid(iter).name() << std::endl;
	// std::cout << *iter << std::endl;
	*/
	
	sortSt st1;
	st1.index = 1;
	sortSt st2;
	st2.index = 0;
	std::vector<sortSt> vec;

	// 扩展容量 会调用拷贝构造函数
	vec.push_back(st1);
	vec.push_back(st2);
	std::sort(vec.begin(), vec.end());

	std::set<sortSt> testSet;
	testSet.insert(st1);
	testSet.insert(st2);
	for(const auto& item : testSet)
		std::cout << "set:" << item.index << std::endl;

	std::set<int> eraseSet;
	eraseSet.insert(1);
	eraseSet.insert(2);
	eraseSet.insert(3);
	eraseSet.insert(4);
	eraseSet.insert(5);

	std::set<int> targetSet;
	targetSet.insert(2);
	targetSet.insert(3);

	std::set<int> s{1};


	cout << "test event" << endl;
	set<std::shared_ptr<event>, com> eventSet, eventSet2;
	auto e1 = std::make_shared<event>();
	e1->time = 1;
	e1->tableID = 1;

	auto e2 = std::make_shared<event>();
	e2->time = 2;
	e2->tableID = 2;

	auto e3  = std::make_shared<event>();
	e3->time = 4;
	e3->tableID = 4;
	auto e4  = std::make_shared<event>();

	eventSet.insert(e2);
	eventSet.insert(e1);


	eventSet2.insert(e3);
	
	
	/*
	auto ptr = *eventSet.begin();
	ptr->time = 3;
	*/

	//eventSet.insert(e3);
	for(auto p : eventSet)
		cout << "set:" <<  p->time << "table:" << p->tableID << endl;

	auto nh = eventSet.extract(e4);
	if(!nh.empty())
	{
		cout << "nh" << endl;
		nh.value()->time = 100;
		eventSet.insert(std::move(nh));
		cout << typeid(nh).name() << endl;
	}
	else
		cout << "no nh" << endl;

	cout << "size:" << eventSet.size() << endl;

	for(auto p : eventSet)
		cout << "set:" <<  p->time << "table:" << p->tableID << endl;
}
	     
