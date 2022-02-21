#include <iostream>
#include <string>

using namespace std;

template <typename T> concept HasSize = requires (T x){ 
	{x.size()} -> std::convertible_to<std::size_t>; 
};

template<typename T> 
requires Incrementable<T> && Decrementable<T> 
void Foo(T t); 

int main()
{
	return 0;
}

