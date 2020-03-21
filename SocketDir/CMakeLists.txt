set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)
cmake_minimum_required(VERSION 3.8)
project(TCPServer)

set(DEBUG_FLAG "-g -Werror -std=gnu++14 -Wno-invalid-source-encoding -fdiagnostics-format=vi")
include_directories(SYSTEM /usr/include)

set(CMAKE_CXX_FLAGS ${DEBUG_FLAG})

add_executable(TCPServer TCPServer.cpp)
add_executable(TCPClient TCPClient.cpp)

