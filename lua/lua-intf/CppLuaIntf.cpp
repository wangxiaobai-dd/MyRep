#include <iostream>
#include <string>
#include "LuaIntf/LuaIntf.h"
//#include "LuaIntf/LuaRef.h"

using namespace std;

#define TRY_RUN_GLOBAL_SCRIPT_FUN1(strFuncName, arg1)  try {LuaIntf::LuaRef func(context, strFuncName);  func.call<LuaIntf::LuaRef>(arg1); }catch (LuaIntf::LuaException& e) { cout << e.what() << endl; }


class Test
{
	public:
	Test(){ cout << "construct test" << endl; }
	int a = 1;
	void add(int n){ a += n; };
	int get(){ return a; }
	void func(){ cout << "func" << endl; }
};

void registerClass(LuaIntf::LuaContext& context)
{
	LuaIntf::LuaBinding(context).beginClass<Test>("Test")
		.addConstructor(LUA_ARGS())
		.addProperty("myA", &Test::get, &Test::add)
		.addFunction("func", &Test::func)
		.endClass();
}


int main()
{
	LuaIntf::LuaContext context;

	registerClass(context);

	context.doFile("helloworld.lua");
	LuaIntf::LuaRef table(context.state(), "me");
	/*
	cout << table.get<int>("he") << endl;
	cout << table.get<string>("name") << endl;
	cout << table.get<string>("gender") << endl;
	*/

	LuaIntf::LuaRef func(context.state(), "add");
	func(1, 2);

	Test test;

	TRY_RUN_GLOBAL_SCRIPT_FUN1("testclass", &test);

	cout << test.a<< endl;
	
	
	return 0;
}
