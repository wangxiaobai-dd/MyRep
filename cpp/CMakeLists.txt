set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)
#set(CMAKE_CXX_COMPILER g++)
#set(CMAKE_C_COMPILER gcc)
cmake_minimum_required(VERSION 3.8)
project(TestRedis)
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")
set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CMAKE_COMMAND} -E time")


#set(DEBUG_FLAG "-g -Werror -std=gnu++14 -Wno-invalid-source-encoding -fdiagnostics-format=vi")
set(DEBUG_FLAG "-g -o2 -Werror -std=gnu++17")
include_directories(SYSTEM /usr/include)
include_directories(nvwa)

#set(Boost_USE_MULTITHREADED OFF)
#find_package(Boost REQUIRED program_options)
#include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS ${DEBUG_FLAG})

#link_directories(/usr/include/hiredis/)
#add_executable(TestTemplate TestTemplate.cpp)
#add_executable(TestEnumClass TestEnumClass.cpp)
#add_executable(TestNullPtr TestNullPtr.cpp)
#add_executable(TestStaticVar TestStatic1.cpp TestStatic2.cpp)
add_executable(TestMass TestMass.cpp)
add_executable(TestDecltype TestDecltype.cpp)
#add_executable(TestDynamicCast TestDynamicCast.cpp)
#target_link_libraries(TestBoost PRIVATE Boost::program_options)

