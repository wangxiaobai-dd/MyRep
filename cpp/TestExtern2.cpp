/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestExtern2.cpp
 * Author        : Meepo
 * Creation Date : 2022-06-10
 * INFO          :
 *
 */


#include <iostream>
#include <string>

#include "TestStatic1.h"


namespace ser{

	A* aa = nullptr;

	void init()
	{
		 aa = new ser::A(10);
	}

	void A::test(){ aa->a; }
}
