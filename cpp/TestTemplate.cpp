//#include <type_traits> 
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <initializer_list>
#include <typeinfo>

// ODR
class Decider
{
	virtual ~Decider(){}
};

extern Decider odr;

// 依赖型基类
template <typename T>
class BBB{
	public:
		//enum E {e1 = 6, e2 = 7};
		//virtual void zero(E e = e1){ std::cout << "zero" <<std::endl;}
		void one(int ){}
};

template <typename T>
class DDD : public BBB<T>
{
	public:
		void f()
		{
			//typename DDD<T>::E e;
			//zero();
			this->one(1); // 依赖型名称实例化时查找
		}

};

struct A{  int a = 0; int b = 0;

	template <typename T>
	void send(){ std::cout << "send : a" << std::endl;}

};

struct B : public A{
	template <typename T>
		void send(){ std::cout << "send : b" << std::endl;}
};

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

// union模板
template<typename T>
union AllocChunk
{
	T object;
	unsigned char bytes[sizeof(T)];
};

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
	
	AllocChunk<int> ch;
	ch.object = 10;
	ch.bytes[2] = 100;
	cout << ch.object << endl;

	// 依赖型基类
	cout << "依赖型基类 "<< endl;
	DDD<int> d; // undefined reference
	d.f();

	// ODR
	const char* name = typeid(odr).name();
	//return sizeof(odr);

	A* bbbb = new B();
	bbbb->send<int>(); // aaa
	
	return 0;
}
