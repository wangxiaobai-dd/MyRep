#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <typeinfo>
#include <map>
#include <vector>
using namespace std;
 
struct sortSt
{
	public:
	int index = 0;

	// 相同对象不能返回true
	bool operator < (const sortSt& info) const
	{
		return this->index > info.index;
	}
	/*friend bool operator < (const sortSt& lhs, const sortSt& rhs)
	{
		return lhs.index < rhs.index;
	}
	*/
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
	st2.index = 1;
	std::vector<sortSt> vec;

	// 扩展容量 会调用拷贝构造函数
	vec.push_back(st1);
	vec.push_back(st2);
	std::sort(vec.begin(), vec.end());

	std::set<sortSt> testSet;
	testSet.insert(st1);
	testSet.insert(st2);
	for(const auto& item : vec)
		std::cout << item.index << std::endl;

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

}
	     
