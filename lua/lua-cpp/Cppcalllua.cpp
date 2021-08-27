#include <iostream>
#include <string>
#include "lua.hpp"

using namespace std;

static void stackDump(lua_State* L)
{
	cout << "\n-------------- dump lua stack start--------------" << endl;
	int i = 0;
	int top = lua_gettop(L); //获取栈顶下标
	cout << top << endl;
	for (i = top; i <= top; --i)
	{
		if (i == 0)
		{
			break;
		}
		int t = lua_type(L, i); //获取栈上数据类型
		switch (t)
		{
			case LUA_TSTRING:
				{
					printf("|INDEX='%d','LUA_TSTRING=%s'|\n", i,lua_tostring(L, i));
				}
				break;
			case LUA_TBOOLEAN:
				{
					printf("|INDEX='%d','LUA_TBOOLEAN=%s'|\n", i,lua_toboolean(L, i) ? "true" : "false");
				}
			case LUA_TNUMBER:
				{
					printf("|INDEX='%d','LUA_TNUMBER=%g'|\n", i,lua_tonumber(L, i));
				}
				break;
			default:
				{
					printf("|INDEX='%d','DEFAULT=%s'|\n", i,lua_typename(L, t));
				}
				break;
		}
	}
	cout << "-------------- dump lua stack end --------------\n" << endl;
}

int main()
{
	lua_State* lua_state = luaL_newstate(); // 创建一个新的Lua虚拟机 
	if(!lua_state)
		return 1;
	luaL_openlibs(lua_state); // 打开一些必要的库，比如print等

	int ret = luaL_dofile(lua_state, "helloworld.lua");
	lua_getglobal(lua_state, "me");
	if (!lua_istable(lua_state, -1))
	{
		std::cout << "error:it is not a table" << std::endl;
	}
	stackDump(lua_state);
	//读取表中的字段
	lua_getfield(lua_state, -1, "name"); // 入栈
	stackDump(lua_state);
	std::cout << "student name = " << lua_tostring(lua_state, -1) << std::endl;
	stackDump(lua_state);

	lua_getfield(lua_state, -2, "gender"); // 入栈
	stackDump(lua_state);
	std::cout << "student gender = " << lua_tostring(lua_state, -1) << std::endl;
	// stackDump(lua_state);

	lua_pushfstring(lua_state, "007"); 


	//lua_pop(lua_state, 1);
	stackDump(lua_state);

	lua_setfield(lua_state, -4, "name"); // 修改表 用栈顶的数值 
	stackDump(lua_state);

	lua_getfield(lua_state, -3, "name");
	std::cout << "student newname = " << lua_tostring(lua_state, -1) << std::endl;
	stackDump(lua_state);

	// lua_settable
	//



	return 0;
}

