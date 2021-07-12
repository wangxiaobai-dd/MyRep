#include <iostream>

/*
 * •int __builtin_ffs (unsigned int x) 
 * 返回x的最后一位1的是从后向前第几位，比如7368（1110011001000）返回4。 
 * •int __builtin_clz (unsigned int x) 
 * 返回前导的0的个数。 
 * •int __builtin_ctz (unsigned int x) 
 * 返回后面的0个个数，和__builtin_clz相对。 
 * •int __builtin_popcount (unsigned int x) 
 * 返回二进制表示中1的个数。 
 * •int __builtin_parity (unsigned int x) 
 * 返回x的奇偶校验位，也就是x的1的个数模2的结果
 */

#include <bitset>
#include <variant>
#include <string>
#include <cassert>
using namespace std;

enum class TYPE : unsigned short
{
	A = 63
};

int main()
{
	/*
	std::variant<int, string> v, w;
	v = "100";
	v = 1011;
	try{
		cout << get<int>(v) << endl;
	}
	catch (const std::bad_variant_access&) {
		cout << get<string>(v) << endl;
	}
	////
	int iTemp = 125;
	bitset<32> bitInt(iTemp);
	cout<<"10进制整型转2进制 "<<bitInt<<endl;

	// 脏数据管理算法
	int count = 0;
	int n = 1; // 10001011
	while(n != 0)
	{
		cout << "builtin" << __builtin_ffsll(n) << endl; // 找出最低位的1的位置 
		n = n & (n - 1);
		count++;
	}
	cout << count << endl;
	n = 139;
	*/
	cout << "builtin" << __builtin_ffsll(0) << endl; // 找出最低位的1的位置 

	cout << "init:" << endl;
	unsigned long m = 0;
	m = (1UL << static_cast<unsigned short>(TYPE::A)) - 1;
	cout << m << endl;
	return 0;
}
