set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)
cmake_minimum_required(VERSION 3.8)
project(CMakeTest)

#XXX_FOUND 代表库是否查找成功
#XXX_INCLUDE_DIRS 代表头文件的路径
#XXX_LIBRARIES 代表库文件的路径
#add_executable(TestCMake TestCMake.cpp)

#会调用FindBZip2.cmake 模块
find_package(BZip2)
if (BZIP2_FOUND)
	include_directories(${BZIP_INCLUDE_DIRS})
	target_link_libraries (TestCMake ${BZIP2_LIBRARIES})
	#找不到 会输出
	#Could NOT find BZip2 (missing: BZIP2_LIBRARIES BZIP2_INCLUDE_DIR) 
endif (BZIP2_FOUND)


#测试模块 
set(SRC_LIB TestCMake.cpp)
add_library(demo9_lib STATIC ${SRC_LIB})

set(CMAKE_INSTALL_LIBDIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_LIBDIR})

#make install
install(TARGETS demo9_lib DESTINATION demo9)
#install(FILES demo9.h DESTINATION demo9)

#set(SRC_EXE demo9_main.cpp)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
#find_package(DEMO9LIB)

if(DEMO9LIB_FOUND)
	add_executable(demo9_main ${SRC_EXE})
	message("found demo9 ${DEMO9LIB_INCLUDE_DIR} ${DEMO9LIB_LIBRARY}")
	include_directories(${DEMO9LIB_INCLUDE_DIR})
	target_link_libraries(demo9_main ${DEMO9LIB_LIBRARY})
else()
	message("not found DEMO9LIB_FOUND")
endif(DEMO9LIB_FOUND)

add_custom_target(dist
	WORKING_DIRECTORY
	${CMAKE_CURRENT_BINARY_DIR}
	COMMAND echo "ehehehe"
	COMMENT
	"test target"
	VERBATIM
	) 
