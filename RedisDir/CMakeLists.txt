set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)
cmake_minimum_required(VERSION 3.8)
project(TestRedis)

set(DEBUG_FLAG "-g -Werror -std=gnu++14 -Wno-invalid-source-encoding -fdiagnostics-format=vi")
include_directories(SYSTEM /usr/include)
include_directories(../ToolDir)
include_directories(proto)

set(CMAKE_CXX_FLAGS ${DEBUG_FLAG})

link_directories(/usr/local/lib)
#同步redis
add_executable(TestRedis TestRedis.cpp)
target_link_libraries(TestRedis hiredis protobuf redisProto)

# proto与redis使用测试
add_subdirectory(proto)

LINK_LIBRARIES(${CMAKE_CURRENT_SOURCE_DIR}/libEventLoop.a)
add_executable(TestASyncRedis TestASyncRedis.cpp)

target_link_libraries(TestASyncRedis hiredis ev protobuf redisProto)
