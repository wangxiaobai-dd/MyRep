set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)
#set(CMAKE_CXX_COMPILER g++)
#set(CMAKE_C_COMPILER gcc)
cmake_minimum_required(VERSION 3.8)
project(TestRedis)

#set(DEBUG_FLAG "-g -Werror -std=gnu++14 -Wno-invalid-source-encoding -fdiagnostics-format=vi")
set(DEBUG_FLAG "-g -Werror -std=gnu++17")
include_directories(SYSTEM /usr/include)
include_directories(nvwa)

#set(Boost_USE_MULTITHREADED OFF)
#find_package(Boost REQUIRED program_options)
#include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS ${DEBUG_FLAG})

#link_directories(/usr/include/hiredis/)
add_executable(TestTemplate TestTemplate.cpp)
add_executable(TestEnumClass TestEnumClass.cpp)

#target_link_libraries(TestMemoryOrder pthread)
#target_link_libraries(TestBoost PRIVATE Boost::program_options)

