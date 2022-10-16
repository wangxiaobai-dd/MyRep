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
//using namespace std;

#include <iostream>
#include <type_traits>
#include <functional>
void test(int a)
{
	std::cout << a ;
}


template <typename Function, typename... Args>
	static std::enable_if_t<std::is_void_v<std::invoke_result_t<Function, Args...>>>
call( Function func)
{
	std::cout << "invoke return void" << std::endl;
	func();
}


template <typename Function, typename... Args>
	static std::enable_if_t<!std::is_void_v<std::invoke_result_t<Function, Args...>>>
call( Function func)
{
	std::cout << "invoke return non-void" << std::endl;
	func();
}

int main() 
{

	auto f = std::bind(test, 1);

	call(f);

}

