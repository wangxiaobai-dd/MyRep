set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)
cmake_minimum_required(VERSION 3.8)
project(Tool)

set(DEBUG_FLAG "-g -Werror -std=gnu++14 -Wno-invalid-source-encoding -fdiagnostics-format=vi")
include_directories(SYSTEM /usr/include)

set(CMAKE_CXX_FLAGS ${DEBUG_FLAG})

#add_executable(TimeTool TimeTool.cpp)
link_directories(/usr/local/lib)
add_executable(EventLoop EventLoop.cpp)
target_link_libraries(EventLoop ev)
