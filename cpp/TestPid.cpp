#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main()
{
	cout << (int)getpid() << endl;
	while(true){}
	return 0;
}

