#include <iostream>
#include <string>
#include <unistd.h>
#include <list>
#include <memory>
#include <map>
#include <deque>
#include <algorithm>
#include <string.h>
#include <set>
#include  <sys/types.h>

using namespace std;

struct REMOVE
{
	int a = 0;
	int b = 0;
	int c = 0;
	bool operator == (const REMOVE& i) const
	{
		return a == i.a;
	}
	map<int, int> mm;
	char arr[50] = {0};
	REMOVE() = default;
	REMOVE(const REMOVE* ref)
	{
		bcopy(&ref, this, sizeof(*this));
	}
	bool operator > (const REMOVE& other) const
	{
		return c > other.c;
	}
};

int main()
{
	char *buffer;
	buffer = getcwd(NULL, 0);
	printf("%s\n", buffer);
	free(buffer);
	char *path;
	path = get_current_dir_name();
	cout<<"path:"<<path<<endl;
	std::string str = path;
	free(path);
	cout << str << endl;


	string value = "a.xml";
	auto iter = value.find(".xml");
	if(iter != std::string::npos)
	{
		cout << value.substr(0, iter) << endl;
	}

	char arr[20][20];
	cout << sizeof(arr[0]) << endl;


	shared_ptr<REMOVE> p = make_shared<REMOVE>();
	map<int, shared_ptr<REMOVE>> mm;
	list<shared_ptr<REMOVE>> ll;
	mm[1] = p;
	ll.push_back(p);
	mm[1]->mm[100] = 10;
	cout << ll.begin()->get()->mm[100] << endl;

	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);

	/*
	int i = 0;
	for_each(d.begin(), d.end(), [&i](int b){ cout << i++ << endl;});
	cout << i << endl;
	i = 0;
	for_each(d.begin(), d.end(), [&i](int b){ cout << i++ << b << endl;});
	*/

	/*
	REMOVE r2;

	REMOVE r3 = r2;
	r2.arr[0] = 'a';
	cout << r2.arr[0] << endl;
	cout << r3.arr[0] << endl;

	std::shared_ptr<REMOVE> pp;
	if(!pp)
		cout << "null" << endl;

		cout << "null" << endl;
		*/
	cout << "======" << endl;
	REMOVE r4,r5,r6,r1;
	r4.a = 4;
	r5.a = 5;
	r6.a = 6;
	r1.a = 1;

	r4.c = 3;
	r5.c = 3;
	r6.c = 2;
	r1.c = 5;

	std::multiset<REMOVE, std::greater<REMOVE>> list;
	list.insert(r4); // 无言
	list.insert(r5); // 那个
	list.insert(r6); // 那个
	list.insert(r1); // 那个
	for(auto iter = list.begin(); iter != list.end(); ++iter)
	{
		cout << iter->a << endl;
	}
	cout << "======" << endl;
	for(auto iter = list.begin(); iter != list.end(); ++iter)
	{
		if(iter->a == 4)
		{
			list.erase(iter);
			list.insert(r4);
			break;
		}
	}
	for(auto iter = list.begin(); iter != list.end(); ++iter)
	{
		cout << iter->a << endl;
	}
	cout << "======" << endl;
	for(auto iter = list.begin(); iter != list.end(); ++iter)
	{
		if(iter->a == 5)
		{
			list.erase(iter);
			list.insert(r5);
			break;
		}
	}
	for(auto iter = list.begin(); iter != list.end(); ++iter)
	{
		cout << iter->a << endl;
	}
	cout << "======" << endl;
	for(auto iter = list.begin(); iter != list.end(); ++iter)
	{
		if(iter->a == 6)
		{
			list.erase(iter);
			list.insert(r6);
			break;
		}
	}
	for(auto iter = list.begin(); iter != list.end(); ++iter)
	{
		cout << iter->a << endl;
	}

	int a[3];
	cout << sizeof(a) << endl;

	int* test = new int(10);
/*
	int f = fork();
	if(f == 0)
		cout << "test child" << *test << endl;
	if(f)
	{
		*test = 11;
		cout << "father" << *test << endl;
	}
	if(f == 0)
		cout << "test child" << *test << endl;
	if(f)
	{
		cout << "father" << *test << endl;
	}
	*/

	int data = 1000;
	printf("data:%d\n", (*(unsigned char*)&data) & (128*1024-1));
	printf("%d\n", (*(unsigned int*)&data) & (128*1024-1));

	sleep(10);

	return 0;
}

