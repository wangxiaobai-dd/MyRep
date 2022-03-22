#include <iostream>
#include <string>

using namespace std;


class A{

	public:
	operator int bitand(){
		return i;
	}
	int i;
};


int main()
{
	A a;
	std::cin >> a;
	std::cout << a;
	return 0;
}

