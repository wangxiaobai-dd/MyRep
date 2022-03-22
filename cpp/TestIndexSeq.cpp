#include <iostream>
#include <string>
#include <tuple>

using namespace std;

template<typename T>
auto getN(T t )
{
	cout << t << endl;
	return t;
}


template <typename ... T>
void DummyWrapper(T... t){}

template<std::size_t... N, typename... Args>
constexpr auto fun(std::tuple<Args...> tup, index_sequence<N...> is) {
	//cout << sizeof...(N) << endl;
	auto t = make_tuple(N...);
	//DummyWrapper(getN(std::get<N>(t))...);
	//(getN(std::get<N>(t)),...);
	((cout << std::get<N>(tup) << endl), ...);// 123

	return t;
}

int main()
{
	std::tuple<int, int, int> tup = {1,2,3};
	auto t = fun(tup, make_index_sequence<3>{});
	/*
	cout << std::get<0>(t) << endl;
	cout << std::get<1>(t) << endl;
	cout << std::get<2>(t) << endl;
	*/
	return 0;
}

