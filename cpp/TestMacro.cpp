#include <iostream>
#include <string>

using namespace std;

void test(int a)
{
	cout << a << endl;
}
#define CHECK(FUNC) FUNC(3)
int main()
{
	CHECK(test);
	return 0;
}

