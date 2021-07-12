#include <boost/python/module.hpp> 
#include <boost/python/def.hpp> 
// g++ py2cppboost.cpp -fPIC -shared -o test2.so -I/usr/include/python2.7 -I/usr/local/include -L/home/ubuntu/DownDir/boost_1_64_0/stage/lib -lboost_python -Wl,--rpath=/home/ubuntu/DownDir/boost_1_64_0/stage/lib 
using namespace boost::python; 

int Add(const int x, const int y) 
{ 
	return x + y + y; 
} 

int Del(const int x, const int y) 
{ 
	return x - y; 
} 

BOOST_PYTHON_MODULE(test2) 
{ 
	def("Add", Add); 
	def("Del", Del); 
	def("Ddd", Del); 
}

