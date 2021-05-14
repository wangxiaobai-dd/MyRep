set(ProjectName "TestDynLib")

file(GLOB DYNLIB_Cpp DynamicTest.cpp)
file(GLOB DYNLIB_Hpp DynamicTest.h)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O0 -Wall -g -ggdb -DDEBUG -fPIC -Wno-unknown-pragmas")

add_library(dynlib SHARED
	${DYNLIB_Cpp}
	${DYNLIB_Hpp})
set_target_properties(dynlib PROPERTIES PREFIX "")


add_executable(UserMain UserMain.cpp NFDynLib.cpp)
target_link_libraries(UserMain dynlib)
target_link_libraries(UserMain dl)

