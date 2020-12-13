set(CMAKE_CXX_COMPLIER g++)
set(CMAKE_C_COMPLIER gcc)
project(GAME_CPP)

set(DEBUG_FLAG "-g -Werror -std=gnu++17")
set(CMAKE_CXX_FLAGS ${DEBUG_FLAG})

add_executable(TestPropertyCalc TestPropertyCalc.cpp)
