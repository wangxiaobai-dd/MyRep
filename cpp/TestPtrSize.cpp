#include <iostream>
#include <string>

using namespace std;

struct A
{
	int a;
	int b;
	int c;
};

int main()
{
	A* a = new A();
	cout << sizeof(*a) << endl;
	return 0;
}

