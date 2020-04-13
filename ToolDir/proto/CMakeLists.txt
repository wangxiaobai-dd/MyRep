
#遍历匹配目录和子目录
file(GLOB_RECURSE PROTOS ${CMAKE_CURRENT_SOURCE_DIR}/*.proto)

#foreach(PROTOFILE ${PROTOS})
#get_filename_component(PB_NAME ${PROTOFILE} NAME_WE)
#	get_filename_component(PB_PATH ${PROTOFILE} PATH)
	
#	set(PB_H ${PB_NAME}.pb.h)
#	set(PB_CC ${PB_NAME}.pb.cc)
#	set(PB_OUT ${CMAKE_CURRENT_SOURCE_DIR}/${PB_H} ${CMAKE_CURRENT_SOURCE_DIR}/${PB_CC})
#	add_custom_command(
#OUTPUT ${PB_OUT}
#		COMMAND protoc -I ${CMAKE_CURRENT_SOURCE_DIR} --proto_path=${PB_PATH} --cpp_out=${CMAKE_CURRENT_SOURCE_DIR} ${PROTOFILE}
#		DEPENDS ${PROTOFILE}
#		)
#endforeach(PROTOFILE ${PROTOS})

#set(LIBRARY_OUTPUT_PATH ../)
#add_library(testProto STATIC ${PB_OUT})

#EXECUTE_PROCESS(COMMAND pkg-config --cflags protobuf 
#	COMMAND awk "{print $2}"
#	COMMAND sed "s/-I//g"
#	OUTPUT_VARIABLE PROTOBUF_INCLUDE)

#EXECUTE_PROCESS(COMMAND pkg-config --libs protobuf 
#	COMMAND awk "{print $1}"
#	COMMAND sed "s/-L//g"
#	OUTPUT_VARIABLE PROTOBUF_LIB)

find_package(Protobuf REQUIRED)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTOS})
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}) 

add_executable(PBTest ProtoTest.cpp ${PROTO_SRCS})

include_directories(../build/proto)

add_custom_command(TARGET PBTest
	PRE_BUILD 
	COMMAND mv ${PROTO_SRCS} ${CMAKE_CURRENT_SOURCE_DIR}
	COMMAND mv ${PROTO_HDRS} ${CMAKE_CURRENT_SOURCE_DIR}
	)
target_link_libraries(PBTest ${Protobuf_LIBRARIES})

