set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)
project(TestRedisPlus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DEBUG_FLAG "-g -Werror")

set(CMAKE_CXX_FLAGS ${DEBUG_FLAG})

add_executable(TestRedis TestRedis.cpp)
target_link_libraries(TestRedis hiredis protobuf redisProto)

# proto”Îredis π”√≤‚ ‘
add_subdirectory(proto)

LINK_LIBRARIES(${CMAKE_CURRENT_SOURCE_DIR}/libEventLoop.a)
add_executable(TestASyncRedis TestASyncRedis.cpp)

target_link_libraries(TestASyncRedis hiredis ev protobuf redisProto)
