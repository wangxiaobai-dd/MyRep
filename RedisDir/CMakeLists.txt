set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)
cmake_minimum_required(VERSION 3.8)
project(TestRedis)

set(DEBUG_FLAG "-g -Werror -std=gnu++14 -Wno-invalid-source-encoding -fdiagnostics-format=vi")
include_directories(SYSTEM /usr/include)

set(CMAKE_CXX_FLAGS ${DEBUG_FLAG})

#link_directories(/usr/include/hiredis/)
add_executable(TestRedis TestRedis.cpp)

target_link_libraries(TestRedis hiredis)
