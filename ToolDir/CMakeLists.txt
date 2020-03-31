set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)
cmake_minimum_required(VERSION 3.8)
project(Tool)

set(DEBUG_FLAG "-g -Werror -std=gnu++14 -Wno-invalid-source-encoding -fdiagnostics-format=vi")
include_directories(SYSTEM /usr/include)

set(CMAKE_CXX_FLAGS ${DEBUG_FLAG})

#add_executable(TimeTool TimeTool.cpp)
#相当于g++ -L 环境变量添加LD_LIBRARY_PATH
link_directories(/usr/local/lib)   

#对所有目标进行链接 相当于g++ -l 完整的库路径
#link_libraries(/usr/local/lib/libev.so.4)
add_executable(EventLoop EventLoop.cpp)

#targetlink 对目标进行链接
target_link_libraries(EventLoop ev)
