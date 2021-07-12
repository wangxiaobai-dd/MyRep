#include <iostream>
#include <string>

#include <random>
#include <iostream>
#include <memory>
#include <functional>
 
void f(int n1, int n2, int n3, const int& n4, int n5)
{
	std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1)
{
	return n1;
}

struct Foo {
	void print_sum(int n1, int n2)
	{
		std::cout << n1+n2 << '\n';
	}
	int data = 10;
};
using namespace std;

int main()
{
	using namespace std::placeholders;  // for _1, _2, _3...
	std::shared_ptr<Foo> foo = std::make_shared<Foo>();
	auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);
	cout << foo.use_count() << endl;
	return 0;
}

