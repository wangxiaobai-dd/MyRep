/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestArrayLen.cpp
 * Author        : Meepo
 * Creation Date : 2022-04-12
 * INFO          :
 *
 */

#include<iostream>
#include <string.h>
using namespace std;

template<class T>

int length(T& arr)
{
    //cout << sizeof(arr[0]) << endl;
    //cout << sizeof(arr) << endl;
    return sizeof(arr) / sizeof(arr[0]);
}

int main()
{
    int arr[] = { 1,5,9,10,9,2 };
	//int arr[];
    // 方法一
    cout << "数组的长度为：" << length(arr) << endl;
    // 方法二
    //cout << end(arr) << endl;
    //cout << begin(arr) << endl;
    cout << "数组的长度为：" << end(arr)-begin(arr) << endl;

	int i = 3;
	unsigned short brr[2][2] = {0};
	brr[1][1] = 3;
	cout << *(brr[0] + i) << endl; 
	cout << brr[0][1] << endl;
	cout << brr[1][1] << endl;

	bzero(brr, sizeof(brr));
	cout << sizeof(brr) << endl;

    return 0;
}
