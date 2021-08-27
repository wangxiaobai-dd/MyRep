project(LuaCpp)
file(GLOB NFLuaScriptPlugin_ROOT_Cpp Cppcalllua.cpp)
file(GLOB NFLuaScriptPlugin_ROOT_Hpp *.h)

include_directories(/home/ubuntu/DownDir/lua-5.3.0/src)

# cpp 调用lua
add_executable(CppCallLua ${NFLuaScriptPlugin_ROOT_Cpp})
# lua 调用c++ 
add_executable(LuaCallCpp Luacallcpp.cpp)

target_link_libraries(CppCallLua liblua.a dl)
target_link_libraries(LuaCallCpp liblua.a dl)

set_target_properties(CppCallLua PROPERTIES OUTPUT_NAME CppCallLua)
set_target_properties(CppCallLua PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}) #set的话CMAKE_XXXXX

set_target_properties(LuaCallCpp PROPERTIES OUTPUT_NAME LuaCallCpp)
set_target_properties(LuaCallCpp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}) #set的话CMAKE_XXXXX


