/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestPlayer.cpp
 * Author        : Meepo
 * Creation Date : 2022-04-14
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <set>

using namespace std;

class Player
{
	public:
		string name;
		int id = 0;
		int score = 0;


	bool operator <(const Player& p) const
	{
		return id > p.id;
	}
};

int main()
{
	std::set<Player> playerSet;
	playerSet.insert({"1001", 1, 20});
	playerSet.insert({"1002", 5, 30});
	playerSet.insert({"1003", 6, 30});
	playerSet.insert({"1004", 2, 50});
	for(const auto& p : playerSet)
	{
		cout << p.name << " id:" << p.id << " score:" << p.score << endl;
	}

	for(auto iter = playerSet.begin(); iter != playerSet.end(); )
	{
		if(iter->score == 30)
			playerSet.erase(iter++);
		else 
			++iter;
	}
	cout << "delete:" <<endl;
	for(const auto& p : playerSet)
	{
		cout << p.name << " id:" << p.id << " score:" << p.score << endl;
	}
	return 0;
}

