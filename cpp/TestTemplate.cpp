//#include <type_traits> 
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <initializer_list>

struct A{  int a = 0; int b = 0;};

struct B : public A{};

struct C { int a = 0; int b = 0; };

template <typename T, typename... Ts>
auto print3(T value, Ts... args)
{
//	std::cout << value << std::endl; // 1
	std::initializer_list<T>{
		([&args] {
			std::cout << args << std::endl; // 2,3
			//std::cout << sizeof(args) << std::endl;
			}(), value)...
	};
}

class Base {
	public:
		int value1;
		int value2;
		Base() {
			value1 = 1;
		}
		Base(int value) : Base() { // 委托 Base() 构造函数
			value2 = value;
		}
};
class Subclass : public Base {
	public:
		using Base::Base; // 继承构造
};

template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
{
	return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

enum class type : int
{
	A = 1
};


void increase(int& v)
{
	v++;
}

template<typename T>
void create(T& t)
{
	t = T();
}

int main()
{
	using namespace std;
	B b{0,0};


	std::cout << "__cplusplus:" << __cplusplus << std::endl;
	std::cout << type::A << std::endl;
	double s = 1;
//	increase(s);
//	int& 不能引用 double 类型的参数，因此必须产生一个临时值来保存 s 的值
	cout << s << endl;

	std::vector<int> v {1,2,3};
	for(auto&& i : v)
		;
	std::cout << v[0] << std::endl;
	int i = 0;
	create(i);
	return 0;
}
