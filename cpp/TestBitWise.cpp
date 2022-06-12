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
#include <cstring>
using namespace std;

void func()
{
    cout << "子线程func开始执行！" << endl;
    //do something
    cout << "子线程func执行结束！" << endl;
}

class A
{
	public:
		A(){ init(); }
		virtual void init(){ cout << "A" << endl;};
	~A(){ cout << "~A" << endl;}
	protected:
	int b;
	private:
	int a;
};

class B
{
	public:
	~B(){ cout << "~B" << endl;}
};

class C : public A
{
	public:
		C(){}
		virtual void init(){ cout << "C" << endl;};
	~C(){ 
		cout << b << endl;
		cout << "~C" << endl;
	
	}
};

class D:public C
{
	~D(){ 
		cout << b << endl;
		cout << "~C" << endl;
	
	}

};

int main()
{
    cout << "主线程main开始执行！" << endl;
    //thread t(func);
    //t.detach();
    cout << "主线程main执行结束！" << endl;
	/*
    uint64_t a = 432865382422222;
    cout << a << endl;
    int b = sizeof(unsigned char);
    int c = 40;
    cout << ((a & ((uint64_t)0xFF << c)) >> c) << endl;

	cout << "info:" << endl;
	int info = 0b1111111;
	auto ptn = (info >> 4)& 0b111;
	info = ptn;
	cout << info << endl;
	*/

    cout << "test" << endl;
	char cc[] = {"game"};
	cout << sizeof(cc[0]) << endl;// 1
	cout << sizeof(cc) << endl;// 5
	cout << strlen(cc+3) << endl;
	char* p = cc;
	cout << sizeof(*p) << endl;
	cout << cc[0] << endl;
	A* aa = new C;
	//aa.a;
	//aa.b;

	unsigned char index = -1;
	++index;
	printf("index:%u\n", index);
    return 0;
}
