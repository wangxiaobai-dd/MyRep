#include <iostream>
#include <string>
#include "DynamicTest.h"
#include "UserMain.h"

using namespace std;

NF_EXPORT void test(User* user)
{
	//cout << "4" << endl;
	user->a = 9;
	user->s.insert(3);
	cout << user->s.size() << endl;
	if(user->s.count(3))
		cout << 2 << endl;
}


NF_EXPORT void con() __attribute__((constructor));
NF_EXPORT void dcon() __attribute__((destructor));


NF_EXPORT void con()
{
	   std::cout << "Constructing library..." << std::endl;
}

NF_EXPORT void dcon()
{
	   std::cout << "Destructing library..." << std::endl;
}
