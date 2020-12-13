#include <iostream>
#include <string>
#include <tuple>

using namespace std;

template<int... N>
decltype(auto) fun(index_sequence<N...> is) {
	return make_tuple(N...);
}

int main()
{
	auto t = fun(make_index_sequence<3>());
	cout << std::get<0>(t) << endl;
	cout << std::get<1>(t) << endl;
	cout << std::get<2>(t) << endl;
	return 0;
}

