#include <iostream>
#include <string>

using namespace std;

void test(int*& a)
{
	a = new int;
}

int main()
{
	int* a = nullptr;
	test(a);
	std::cout << *a << std::endl;
	return 0;
}

