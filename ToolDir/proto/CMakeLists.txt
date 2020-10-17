
#遍历匹配目录和子目录
#file(GLOB_RECURSE PROTOS message2.proto)

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
#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTOS})
include_directories(build)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}) 

#PBTest
#add_executable(PBTest ${PROTO_SRCS} ProtoTest.cpp)
#target_link_libraries(PBTest ${Protobuf_LIBRARIES})

#add_custom_command(TARGET PBTest
#	PRE_BUILD 
#	COMMAND mv ${PROTO_SRCS} ${CMAKE_CURRENT_SOURCE_DIR}
#	COMMAND mv ${PROTO_HDRS} ${CMAKE_CURRENT_SOURCE_DIR}
#	)
#PBTest2
#add_executable(PBTest2 ProtoTest2.cpp)
#target_link_libraries(PBTest2 ${Protobuf_LIBRARIES})

#PBTest3
file(GLOB_RECURSE PROTOS selfMessage.proto)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTOS})
add_executable(PBTest3 ${PROTO_SRCS} ProtoTest3.cpp)
target_link_libraries(PBTest3 ${Protobuf_LIBRARIES})

file(GLOB_RECURSE PROTOS2 message2.proto)
protobuf_generate_cpp(PROTO_SRCS2 PROTO_HDRS2 ${PROTOS2})
add_executable(PBTest4 ${PROTO_SRCS2} ProtoTest4.cpp)
target_link_libraries(PBTest4 ${Protobuf_LIBRARIES})

add_custom_target(ctags
	WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
	COMMAND echo ${CMAKE_CURRENT_LIST_DIR}
	COMMAND ctags -R -h ".cc.cpp.h.proto" --append=yes -o tags
	#COMMAND mv tags ${CMAKE_CURRENT_LIST_DIR}
	COMMENT
	"ctags successful create"
	VERBATIM
	) 

add_custom_target(desset
	WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
	COMMAND protoc --cpp_out=${CMAKE_CURRENT_LIST_DIR} --descriptor_set_out=des.set message.proto
	COMMAND mv des.set ../build/proto/
	COMMAND rm message.pb.h message.pb.cc
	COMMENT
	"desset successful create"
	VERBATIM
	) 
