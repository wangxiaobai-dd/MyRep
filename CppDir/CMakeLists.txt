#set(CMAKE_CXX_COMPILER clang++)
#set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)
cmake_minimum_required(VERSION 3.8)
project(TestRedis)

#set(DEBUG_FLAG "-g -Werror -std=gnu++14 -Wno-invalid-source-encoding -fdiagnostics-format=vi")
set(DEBUG_FLAG "-g -Werror -std=gnu++17")
include_directories(SYSTEM /usr/include)

set(CMAKE_CXX_FLAGS ${DEBUG_FLAG})

#link_directories(/usr/include/hiredis/)
add_executable(TestCPP Test.cpp)
add_executable(TestCPP2 Test2.cpp)
add_executable(TestCPP3 TestThreadPool.cpp)
add_executable(TestMorden TestMorden.cpp)

target_link_libraries(TestCPP3 pthread)

