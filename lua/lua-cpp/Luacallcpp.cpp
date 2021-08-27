#include <iostream>
#include <string>

using namespace std;

#include <stdio.h>

extern "C" {

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

}

lua_State* L;

static int Average(lua_State *L)
{
	//code3
	int n = lua_gettop(L);
	double sum = 0;
	//code4
	for (int i = 1; i <= n; ++i)
	{
		sum += lua_tonumber(L, i);
	}
	//code5
	lua_pushnumber(L, sum / n);
	lua_pushnumber(L, sum);
	//code6
	return 2;
}

int main(int argc, char *argv[])
{
	L = luaL_newstate();
	luaL_openlibs(L);

	//code1
	lua_register(L, "average", Average);
	//code2
	luaL_dofile(L, "luacallcpp.lua");
	lua_close(L);

	printf("Press enter to exit...");

	return 0;
}
