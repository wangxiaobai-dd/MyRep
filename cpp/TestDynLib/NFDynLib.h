
#ifndef NF_DYNLIB_H
#define NF_DYNLIB_H

#include <stdio.h>
#include <iostream>


struct HINSTANCE__;
typedef struct HINSTANCE__* hInstance;

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

	std::cout << "Load Lib: " << name << std::endl;
    }

    ~NFDynLib()
    {

    }

    bool Load();

    bool UnLoad();

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
