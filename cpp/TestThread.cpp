/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestThread.cpp
 * Author        : Meepo
 * Creation Date : 2022-10-21
 * INFO          :
 *
 */
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
 #include <unistd.h>

void printAll(int a, int b, int c)
{
	std::string str;
    std::cout << a << " " << b << " " << c << std::endl;
}
void add(int a, int b, int&c)
{
    c += a + b;
}

std::mutex queue_mutex;
void printString(std::string a)
{
	//std::unique_lock<std::mutex> lock(queue_mutex);
	std::string str("print:");
	str += a;
	str += a;
	str += a;
	str += a;
	str += a;
	str += a;
	str += a;
	str += a;
	str += a;
	str += a;
	std::cout << str << std::endl;
}

void testThreadInit()
{
    int a = 1;
    int b = 2;
    int c = 3;
		std::thread t{[=]{ 
			for(int i = 0; i < 100; ++i)
				printString(std::to_string(i));
		}};
		std::thread t2{[=]{ 
			for(int i = 11; i < 200; ++i)
				printString(std::to_string(i));
		}};
		t.join();
		t2.join();
}

int main()
{
    testThreadInit();
    return 0;
}

