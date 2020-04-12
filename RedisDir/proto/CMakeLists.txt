
#遍历匹配目录和子目录
file(GLOB_RECURSE PROTOS ${CMAKE_CURRENT_SOURCE_DIR}/*.proto)

foreach(PROTOFILE ${PROTOS})
	get_filename_component(PB_NAME ${PROTOFILE} NAME_WE)
	get_filename_component(PB_PATH ${PROTOFILE} PATH)
	
	set(PB_H ${PB_NAME}.pb.h)
	set(PB_CC ${PB_NAME}.pb.cc)
	
	set(PB_OUT ${CMAKE_CURRENT_SOURCE_DIR}/${PB_H} ${CMAKE_CURRENT_SOURCE_DIR}/${PB_CC})

	add_custom_command(
		OUTPUT ${PB_OUT}
		COMMAND protoc -I ${CMAKE_CURRENT_SOURCE_DIR} --proto_path=${PB_PATH} --cpp_out=${CMAKE_CURRENT_SOURCE_DIR} ${PROTOFILE}
		DEPENDS ${PROTOFILE}
		)
endforeach(PROTOFILE ${PROTOS})

set(LIBRARY_OUTPUT_PATH ../)
add_library(redisProto STATIC ${PB_OUT})
