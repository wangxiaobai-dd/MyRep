/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestDownCast.cpp
 * Author        : Meepo
 * Creation Date : 2022-06-06
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <cassert>

using namespace std;


template<typename To, typename From>
inline To implicit_cast(From const &f)
{
  return f;
}

class ScenePk;

template<typename To, typename From>
inline enable_if_t<!std::is_same_v<From, ScenePk>, To> down_cast(From* f)                  
{
  if (false)
  {
    implicit_cast<From*, To>(0);
  }

#ifdef _ALL_SUPER_GM
  assert(f != NULL && dynamic_cast<To>(f) != NULL);
  cout << "ohohoho" << endl;
#endif
  return static_cast<To>(f);
}


template<typename To, typename From>
inline enable_if_t<std::is_same_v<From, ScenePk>, To> down_cast(From* f)   
{
  if (false)
  {
    implicit_cast<From*, To>(0);
  }

#ifdef _ALL_SUPER_GM
  assert(f != NULL && dynamic_cast<To>(f) != NULL);
  assert(f->type == 1);  // RTTI: debug mode only!
  cout << "hahah" << endl;
#endif
  return static_cast<To>(f);
}

struct ScenePk
{
	ScenePk(int _type = 0): type(_type){}
	virtual ~ScenePk(){}
	int type = 0;
};

struct SceneUser : public ScenePk
{
	SceneUser() : ScenePk(1){}
};

struct SceneNpc
{};

struct A{

	virtual ~A(){}
};

struct B : public A{};

int main()
{
	throw std::runtime_error("message");
	/*
	ScenePk* p = new SceneUser();
	SceneUser* user = down_cast<SceneUser*>(p);
	cout << user->type << endl;

	ScenePk pp1;
	//down_cast<SceneNpc*>(&pp1);

	A* a = new B();
	down_cast<B*>(a);
	*/

	return 0;
}

