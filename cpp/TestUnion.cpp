#include <iostream>
#include <string>
#include <unistd.h>
#include <list>
#include <memory>
#include <map>
#include <deque>
#include <algorithm>
#include <string.h>
#include <set>
#include  <sys/types.h>

using namespace std;

union alignment {
	size_t sz;
	void *ptr;
	//double dbl;
};

int main()
{
	cout << sizeof(alignment) << endl;
	return 0;
}

