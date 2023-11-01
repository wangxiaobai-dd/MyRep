#include <iostream>
#include <string>
#include <vector>


#define MACRO_HELPER_SIZE(...) MARCO_HELPER(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define MARCO_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, n, ...) n


#define GET_NAME(s) GET_NAME_HELPER s 
#define GET_NAME_HELPER(...)

#define TO_STRING(x) TO_STRING_HELPER(x)
#define TO_STRING_HELPER(x) #x

class TestClass 
{
	public:
	TestClass() = default;	// a
	//TestClass(const TestClass&) = delete;	// b 
	TestClass& operator=(const TestClass& ) = delete; // c
	//~TestClass() = delete; // d
};

template<typename T1, typename T2>
class TSize
{
	union
	{
		T1 a:1;
		T1 b:2;
		T1 c:4;
		T1 e:8;
		T2 f:16;
	};
};


int main()
{
	std::cout << MACRO_HELPER_SIZE(3, 2, 1, 0) << std::endl;

	std::cout << TO_STRING(GET_NAME((int) a)) << std::endl;


	TestClass tc;
	std::vector<TestClass> v;
	v.push_back(tc);

	std::cout << sizeof(TSize<short, char>) << std::endl;

	return 0;
}

