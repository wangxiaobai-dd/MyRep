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
using namespace std;

void func()
{
    cout << "子线程func开始执行！" << endl;
    //do something
    cout << "子线程func执行结束！" << endl;
}

int main()
{
    cout << "主线程main开始执行！" << endl;
    //thread t(func);
    //t.detach();
    cout << "主线程main执行结束！" << endl;
    uint64_t a = 432865382422222;
    cout << a << endl;
    int b = sizeof(unsigned char);
    int c = 40;
    cout << ((a & ((uint64_t)0xFF << c)) >> c) << endl;
    return 0;
}
