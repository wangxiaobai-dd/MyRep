#ifndef _DYNLIB_H_
#define _DYNLIB_H_

#include <stdio.h>
#include <iostream>
#include <dlfcn.h>
#define DYNLIB_HANDLE void*
#define DYNLIB_LOAD( a ) dlopen( a, RTLD_LAZY | RTLD_GLOBAL)
#define DYNLIB_GETSYM( a, b ) dlsym( a, b )
#define DYNLIB_UNLOAD( a ) dlclose( a )

class NFDynLib
{

	public:

		NFDynLib(const std::string& name)
		{
			mbMain = false;
			mstrName = name;
			mstrName.append(".so");
			printf("LoadPlugin:%s\n", mstrName.c_str());
		}

		~NFDynLib()
		{

		}

		 bool Load()
		 {
			 std::string strLibPath = "./";
			 strLibPath += mstrName;
			 mInst = (DYNLIB_HANDLE)DYNLIB_LOAD(strLibPath.c_str());
			 return mInst != nullptr;
		 }
		 bool UnLoad()
		 {
			 DYNLIB_UNLOAD(mInst);
			 return true;
		 }

		 const std::string& GetName(void) const
		 {
			 return mstrName;
		 }

		 const bool GetMain(void) const
		 {
			 return mbMain;
		 }

		 void* GetSymbol(const char* szProcName);

	protected:

		 std::string mstrName;
		 bool mbMain;

		 DYNLIB_HANDLE mInst;
};
#endif
