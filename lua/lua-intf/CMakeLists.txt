project(LuaCpp)
file(GLOB NFLuaScriptPlugin_ROOT_Cpp CppLuaIntf.cpp)
file(GLOB NFLuaScriptPlugin_ROOT_Hpp *.h)

include_directories(/home/ubuntu/DownDir/lua-5.3.0/src)
include_directories(LuaIntf)

# cpp 调用lua
add_executable(testIntf ${NFLuaScriptPlugin_ROOT_Cpp})

target_link_libraries(testIntf liblua.a dl)

set_target_properties(testIntf PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}) #set的话CMAKE_XXXXX



