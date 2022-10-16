/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestMetaProgram.cpp
 * Author        : Meepo
 * Creation Date : 2022-08-17
 * INFO          :
 *
 */


#include <iostream>
#include <type_traits>
#include <tuple>
#include <string>

/*

struct Foo {};

struct Bar {};

class Baz : Foo, public Bar {
	int x;
};

class NonStdLayout : public Baz {
	int y;
};

template<typename Sig>
struct signature;

template<typename R, typename ...Args>
struct signature<R(Args...)>
{
	using type = std::tuple<Args...>;
};

template<typename F>
concept is_fun = std::is_function_v<F>;

template<is_fun F>
auto arguments(const F &) -> typename signature<F>::type;

void foo(const std::string &, int, double)
{}

*/

int main() 
{
	/* need gcc-12
	std::cout << std::boolalpha
		<< std::is_pointer_interconvertible_base_of_v<Bar, Baz> << '\n'
		<< std::is_pointer_interconvertible_base_of_v<Foo, Baz> << '\n'
		<< std::is_pointer_interconvertible_base_of_v<Baz, NonStdLayout> << '\n'
		<< std::is_pointer_interconvertible_base_of_v<NonStdLayout, NonStdLayout> << '\n';
	static_assert(std::is_same_v<decltype (arguments(foo)), 
			std::tuple<const std::string &, int, double>>);
		*/
}
