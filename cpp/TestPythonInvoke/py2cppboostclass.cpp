
#include <boost/python.hpp> 
using namespace boost::python; 

class Test 
{ 
	public: 
		int Add(const int x, const int y) 
		{ 
			return x + y; 
		} 

		int Del(const int x, const int y) 
		{ 
			return x - y; 
		} 
}; 

BOOST_PYTHON_MODULE(test3) 
{ 
	class_<Test>("Testt") 
		.def("Add", &Test::Add) 
		.def("Del", &Test::Del); 
}

/*
 * 两种方法
 * test3.Testt.Add(test3.Testt(),1,2)
 *
 * test = test3.Test()
 * test.Add(1,2) 
 */
