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
#include <arpa/inet.h>
#include <cstdio>
#include <type_traits>
#include <typeinfo>

using namespace std;

typedef unsigned int DWORD;

int testChangePara(...)
{
	return 0;
}

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

struct TEST
{
	unsigned short a = 0;
	unsigned short b = 0;
	unsigned short c = 0;
	unsigned short d = 0;
};

int test1()
{
	int *aa = new int;
	cout << "*aa" << aa << endl;
	return *aa;
}

int test2()
{
	int *aa = new int;
	cout << "*aa" << aa << endl;
	return *aa;
}

void test3()
{
	int a;// 乱的
	cout << "test3:"<< &a << endl; 
}

void test4()
{
	int a;
	cout << "test4:" << &a << endl; // 0x7ffd50370694
	test3(); // 向下增长 0x7ffd50370674
	
}

class A
{
	public:
	    

	std::string mStr;

	bool operator == (const char* s) const
	{ 
		return 0 == strcmp(mStr.c_str(), s);
	}
	operator const char* () const 
	{
		return mStr.c_str();
	}
	const int ccc = 1;
	const static int ccc1 = 2;
};

class sortItem
{
	public:
		std::string name;
		int score;
		sortItem(const std::string& name, const int& score = 0)
		{
			this->name = name;
			this->score = score;
		}
		bool operator == (const sortItem& rhs) const
		{
			return this->name == rhs.name;
		}
		bool operator < (const sortItem& rhs) const
		{
			return score > rhs.score;
		}
};
#define safe_delete(x) { if(x) {delete [](x); (x) = NULL;}}

void testItem(unsigned char **data)
{
	*data = new unsigned char[100000];
	bzero(*data, 100000);
	safe_delete(*data);
//*data = NULL;
}


void testHanZi(const char* newName)
{
	// 8 指针大小
	// 不是数组大小
	cout << "testhanzi" << sizeof(newName) << endl;
}

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
	auto eiter = list.begin();
	list.clear();
	cout << (*eiter).a;
	cout << (*eiter).a;
	if(eiter != list.end())
		cout << "erase" << endl;

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

	//sleep(10);

	std::map<int, int> testIterM;
	testIterM[1] = 2;
	testIterM[3] = 2;
	auto mmIter = testIterM.begin();
	auto mmCopy = mmIter;
	//++mmIter;
	//++mmCopy;
	testIterM.erase(mmIter);
	testIterM[4] = 2;
	++mmCopy;
	//testIterM[5] = 2;
	//++mmCopy;
	//cout << "copy" << (mmCopy)->first << mmCopy->second << endl; 
	//删除原来迭代器 ++会有问题
	//无意义的测试
	cout << (mmCopy)->first << endl;

	std::vector<int*> llist;
	int* ai = new int(2);
	int* bi = new int(3);
	llist.push_back(ai);
	llist.push_back(bi);
	auto lliter = llist.begin();
	auto copyLter = lliter; // 拷贝了地址
	//llist.clear();
	llist.erase(lliter);
	//llist.shrink_to_fit();
	//*(*lliter) = 19;
	//*(*(++lliter)) = 20;// 不会crash
	//*(*(copyLter))  = 20;
	//:w
	//cout << *(*lliter) << endl;
	//cout << *(*(++copyLter)) << endl;
	///cout << *(*(lliter)) << endl;
	//cout << *(*(++copyLter)) << endl;
	// 虽然clear 但是那块内存还在 如果fit后 指向未知
	//

	TEST t;
	(*(unsigned int*)&t.b) = -2;
	cout << "a: " << t.a << endl;
	cout << "b: " << t.b << endl;
	cout << "c: " << t.c << endl;
	cout << "d: " << t.d << endl;
	// a = ? , b = ? , c = ?, d = ? 
	//
	cout << &t << endl;
	cout << &t.b << endl;
	cout << &t.c << endl;  // 在一个栈帧内，局部变量是如何分布到栈帧里的（所谓栈帧布局，stack frame layout），这完全是编译器的自由
	TEST t2;
	cout << "t2:" << &t2 << endl;
	short s=1;
	if(s == htons(s))cout<<"大端"<<endl;
	else cout<<"小端"<<endl;

	int aa;
	int bb;
	cout << "aa:" << &aa << endl;
	cout << "bb:" << &bb << endl;

	test4();

	 char c[] = {"GAME\0"}; // 6
	 char c1[] = {"GAME"}; // 5
	 cout << sizeof(c) << endl;
	 cout << sizeof(c1) << endl;
	 

	 int temsp = 100; 

	 temsp *= 1 + 20/100.0;
	 cout << temsp << endl;

	 cout << typeid(decltype(test4)).name() << endl;
	 std::function<void(int)> fuc;
	 if(fuc)
	 fuc(3);
	 fuc = std::function<void(int)>();
	 if(fuc)
	 fuc(3);

	 A testA;
	 if(testA == "") 
		 cout << "1" << endl;

	 if("" == testA)
		 cout << "2" << endl;

	 std::set<sortItem> sortSet = std::set<sortItem>();
	 sortSet.insert({"AAA", 63});
	 sortSet.insert({"BBB", 98});
	 sortSet.insert({"CCC", 89});
	 sortSet.insert({"DDD", 100});
		 cout << "test" << endl;
	 {
		 auto sIter = sortSet.find({"BBB"});
		 if(sIter != sortSet.end())
			 cout << "1 " <<  sIter->score << endl;
	 }

	 for(auto sIter = sortSet.begin(); sIter != sortSet.end(); ++sIter)
	 {
		 if(*sIter == sortItem{"BBB"})
		 {
			 cout << "2 " << sIter->score << endl;
			 break;
		 }
	 }
	 {
		 auto sIter = std::find(sortSet.begin(), sortSet.end(), sortItem{"BBB"});
		 if(sIter != sortSet.end())
			 cout << "3 " << sIter->score << endl;
	 }
	 for(auto sIter = sortSet.begin(); sIter != sortSet.end(); ++sIter)
	 {
		 if(sIter->name == "BBB")
		 {
			 cout << "4 " << sIter->score << endl;
			 break;
		 }
	 }
	auto mmIterbegin = testIterM.begin();
	auto mmco = mmIterbegin;
	--mmco;
	if(mmco == testIterM.end())
		cout << "end" << endl;


	sortItem *item;
	testItem((unsigned char**)&item);
	if(item)
		cout << "item " << endl;
	safe_delete(item);

	DWORD one = 10;
	DWORD two = 20;
	int three = one - two;
	if(three > 0)
		cout << three << endl;
	else
		cout << "negative " << endl;

	 char hanzi[1000]={1,1,1,4,0};
	 //bzero(hanzi, sizeof(hanzi));
	 //strncpy(hanzi, "呵", 2);
	 //cout << strlen(hanzi) << endl;
	 //cout << sizeof(hanzi) << endl;
	 //cout << hanzi << endl;
	 //cout << "呵呵额额" <<endl;
	 testHanZi(hanzi);

	 std::string testStrncpy;
	 strncpy(hanzi, testStrncpy.c_str(), 1000);
	 cout << strlen(hanzi) << endl;
	 cout << hanzi[0] << endl;
	
	 return 0;
}

