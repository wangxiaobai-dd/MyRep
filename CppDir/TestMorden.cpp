#include <type_traits> 
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

template <class T, T v>
struct integral_constant {
  static const T value = v;
  typedef T value_type;
  typedef integral_constant type;
};

template <bool condition,
          typename Body>
struct WhileLoop;

template <typename Body>
struct WhileLoop<true, Body> {
  typedef typename WhileLoop<Body::cond_value, typename Body::next_type>::type type;
};

template <typename Body>
struct WhileLoop<false, Body> {
  typedef
    typename Body::res_type type;
};

template <typename Body>
struct While {
  typedef typename WhileLoop<Body::cond_value, Body>::type type;
};

template <int result, int n>
struct SumLoop {
  static const bool cond_value =
    n != 0;
  static const int res_value = result;
  typedef integral_constant<int, res_value>
    res_type;
  typedef SumLoop<result + n, n - 1>
    next_type;
};

template <int n>
struct Sum {
  typedef SumLoop<0, n> type;
};


template <typename T>
struct has_reserve
{
	struct good { char dummy; };
	struct bad { char dummy[2]; };
	template <class U, void (U::*)(size_t)> struct SFINAE{}; // 第二个参数是第一个参数的成员函数指针 参数类型是size_t
	template <class U> static good reserve(SFINAE<U, &U::reserve>* ); 

	template <class U> static bad reserve(...);
        static const bool value = sizeof(reserve<T>(nullptr) == sizeof(good));	
};

template <typename Container> 
	typename std::enable_if_t<std::is_same<Container, std::map<typename Container::key_type, typename Container::mapped_type>>::value>
test(Container& cont)
{
	cont[2] = 1;
}

template <typename Container>  
	std::enable_if_t<std::is_same<Container, std::set<typename Container::value_type> >::value>
test(Container& cont)
{
	//cont.insert(1);
}

/*
template<class Container, class = std::enable_if_t<
	std::is_same<Container, std::map<typename Container::key_type, typename Container::mapped_type> >::value ||
	std::is_same<Container, std::unordered_map<typename Container::key_type, typename Container::mapped_type> >::value>>
void FC(Container& fc)
{
	test(fc[2]);
}
*/

template<class Container> std::enable_if_t<
	std::is_same<Container, std::map<typename Container::key_type, typename Container::mapped_type> >::value ||
	std::is_same<Container, std::unordered_map<typename Container::key_type, typename Container::mapped_type> >::value>
FC(Container& fc)
{
	typename Container::key_type tmp = 1;
	std::cout << tmp << std::endl;
	test(fc[2]);
}

template <typename T, class Container>
void FC(Container& fc)
{

}

template <typename Container>
auto append(Container& cont)->decltype(std::declval<Container&>().insert(typename Container::value_type(typename Container::key_type(), typename Container::mapped_type())), void())
{
	test(cont[1]);
	cont[1][1] = 2;
}

template <typename Container>
auto append(Container& cont)->decltype(std::declval<Container&>().insert(typename Container::key_type()), void())
{
	cont.insert(100);
}

struct MM
{};

int main()
{
	//std::map<int, int> mmm;
	std::unordered_map<int, int> mmm2;
	std::set<int> sss;
	std::set<MM> sss2;
	//test(mmm);
	//test(mmm2);
	//test(sss);
//	test(sss2);
	std::map<int, std::map<int, int>> mmm;
	std::map<int, std::set<int>> sss3;
	FC(mmm);
	FC(sss3);
	
	append(mmm);
	//append(mmm2);
//	append2(mmm);
	append(sss);

	std::cout << mmm[1][1] << std::endl;
	std::cout << *sss.begin() << std::endl;

	return 0;
}
