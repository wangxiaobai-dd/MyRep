#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void test()
{

}

struct A
{
	char arr[100] = {0};
};

int main()
{
	A* aptr = new A();
	strncpy(aptr->arr, "aaaa", 99);
	string str(aptr->arr);
	printf("%p\n", aptr->arr);
	printf("%p\n", str.c_str());
	delete aptr;
	printf("%p\n", str.data());

	string endwith = {"dir/"};
	cout << endwith.ends_with("/") << endl;
	
	return 0;
}

