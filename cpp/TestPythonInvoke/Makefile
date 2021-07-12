
all:
	$(warning PATH::::  $(LD_LIBRARY_PATH))
	#g++ py2cppboost.cpp -fPIC -shared -o test2.so -I/usr/include/python2.7 -I/usr/local/include -L/home/ubuntu/DownDir/boost_1_64_0/stage/lib -lboost_python 
	g++ py2cppboost.cpp -fPIC -shared -o test2.so -I/usr/include/python2.7 -I/usr/local/include -L/home/ubuntu/DownDir/boost_1_64_0/stage/lib -lboost_python -Wl,--rpath=/home/ubuntu/DownDir/boost_1_64_0/stage/lib 
	g++ py2cppboostclass.cpp -fPIC -shared -o test3.so -I/usr/include/python2.7 -I/usr/local/include -L/home/ubuntu/DownDir/boost_1_64_0/stage/lib -lboost_python -Wl,--rpath=/home/ubuntu/DownDir/boost_1_64_0/stage/lib 
