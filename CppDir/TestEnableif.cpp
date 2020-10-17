//#include <type_traits> 
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

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

// enable_if
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
	cont.insert(1);
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

// decltype
template <typename Container>
auto append(Container& cont)->decltype(std::declval<Container&>().insert(typename Container::value_type(typename Container::key_type(), typename Container::mapped_type())), void())
{
	test(cont[1]);
	cont[1][1] = 2;
}

template <typename Container>
auto append(Container& cont)->std::void_t<decltype(std::declval<Container&>().insert(typename Container::key_type()))>
{
	cont.insert(100);
}

template <typename Container>
auto append(Container& cont)->decltype(std::declval<Container&>().push_back(typename Container::value_type()), void())
{
	cont.push_back(100);
}

template <typename T>
struct ContType
{
	struct NO { char tmp; };
	struct S { char tmp[2];};
	struct V { char tmp[3];};
	struct M { char tmp[4];};
	/*
	template <class U, void(U::*)(size_t)> 
	struct SFINAE
	{};
	*/
	template <class U, void (U::*)(const typename U::value_type&)> 
	struct SFINAE
	{};

	template <class U, std::pair<typename U::iterator, bool> (U::*)(const typename U::value_type&)> 
	struct SFINAE_S
	{};

	template <class U> 
	static V add(SFINAE<U, &U::push_back>*);

	template <class U> 
	static S add(SFINAE_S<U, &U::insert>*);

	template <class U> 
	static NO add(...);

	static constexpr int value = sizeof(add<T>(nullptr)) == sizeof(V);
	static constexpr int value1 = sizeof(add<T>(nullptr)) == sizeof(S);
};

template <typename Container>
void testCT(Container& c, typename Container::value_type t)
{
	if constexpr (ContType<Container>::value == 1)
	{
		std::cout << "testCT:" << 1 << std::endl;
		c.push_back(t);
	}
	else if constexpr (ContType<Container>::value1 == 1)
	{
		std::cout << "testCT:" << 2 << std::endl;
		c.insert(t);
	}
}

/*
// 重复定义
template <typename Container>
auto append(Container& cont)->std::void_t<decltype(std::declval<Container&>().push_back(typename Container::value_type()))>
{
	cont.push_back(100);
}
*/

/*
template <template <typename T, typename CONT>typename MAP, typename T, typename CONT>
void save(MAP<T, CONT>& m)
{
	test(m[1]);
}
*/

template <template <typename T, typename CONT>typename MAP, typename T, typename CONT>
auto save(MAP<T, CONT>& m)->decltype(std::declval<MAP<T, CONT>&>().insert(typename MAP<T, CONT>::value_type(typename MAP<T, CONT>::key_type(), typename MAP<T, CONT>::mapped_type())), void())
{
	test(m[1]);
}

struct MM
{};

int main()
{
	std::unordered_map<int, std::map<int, int>> tmpMap1;
	save(tmpMap1);

	std::map<int, std::map<int, int>> tmpMap2;
	append(tmpMap2);
	FC(tmpMap2);

	std::map<int, std::set<int>> sss3;
	FC(sss3);
	
	std::set<int> sss;
	append(sss);
	test(sss);

	std::vector<int> vvv;
	append(vvv);

	//std::cout << sss.size() << std::endl;

	std::cout << "ContType:" << ContType<std::vector<int>>::value << std::endl;
	std::cout << "ContType:" << ContType<std::set<int>>::value1 << std::endl;
	std::cout << "ContType:" << ContType<std::set<int>>::value << std::endl;
//	std::cout << "ContType:" << ContType<std::map<int, int>>::value3 << std::endl;
//
	testCT(vvv, 1);
	testCT(sss, 1);
	
	return 0;
}
