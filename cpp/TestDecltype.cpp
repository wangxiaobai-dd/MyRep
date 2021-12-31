#include <iostream>
#include <string>
#include <type_traits>

int value = 0;
using namespace std;

class A
{
	public:
		static void store2() { value = 2; }
		void store3() { value = 3; }
};

int main()
{
	A a;
	decltype(&A::store2) f = A::store2;
	cout << f << endl;
	return 0;
}

