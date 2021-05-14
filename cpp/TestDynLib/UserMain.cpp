#include <iostream>
#include <string>
#include "DynamicTest.h"
#include <unistd.h>
#include <memory>
#include "NFDynLib.h"
#include <map>
#include "UserMain.h"

using namespace std;

using DLL_START_PLUGIN_FUNC = void(*)(User*);

std::map<std::string, std::shared_ptr<NFDynLib>> libMap;
void reload(std::string name)
{
	auto iter = libMap.find(name);
	if(iter != libMap.end())
	{
		iter->second->UnLoad();
		libMap.erase(iter);
	}
	std::shared_ptr<NFDynLib> pLib = std::make_shared<NFDynLib>(name);
	bool bLoad = pLib->Load();
	if(!bLoad)
	{
		cout << "reload fail" << endl;
		return;
	}
	libMap[name] = pLib;
}

int main()
{
	std::string libName = "dynlib";
	std::shared_ptr<NFDynLib> pLib = std::make_shared<NFDynLib>(libName);
	bool bLoad = pLib->Load();
	if(!bLoad)
	{
		cout << "bLoad false" <<  dlerror() << endl;
		return 0;
	}
	libMap[libName] = pLib;
	DLL_START_PLUGIN_FUNC pFunc = (DLL_START_PLUGIN_FUNC)pLib->GetSymbol("test");
	if(!pFunc)
	{
		cout << "func false" << endl;
		return 0;
	}
	User* u = new User();
	/*
	void *handle = dlopen("dynlib.so", RTLD_LAZY);
	DLL_START_PLUGIN_FUNC pFunc = (DLL_START_PLUGIN_FUNC)dlsym(handle,"test");
	if(!pFunc)
	{
		cout << "func2 false" << endl;
		return 0;
	}
	*/
	
	int a = 0;
	while(a++ < 10)
	{
		//test();
		cout << "before change:" << u->a << endl;
		pFunc(u);
		cout << "after change:" << u->a << endl;
		if(a == 8)
		{
			reload(libName);
			pFunc = (DLL_START_PLUGIN_FUNC)libMap[libName]->GetSymbol("test");
			if(!pFunc)
			{
				cout << "reload pFunc fail" << endl;
				return 0;
			}
		}
		sleep(2);
	}

	return 0;
}

