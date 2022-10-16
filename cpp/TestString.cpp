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

	unsigned char buf[5] = {0};
	buf[1] = 'a';
	std::string strs;
	strs.assign(std::begin(buf), std::end(buf)-1);

	char buf2[5];
	strs.assign(buf2, 5);
	
	return 0;
}

