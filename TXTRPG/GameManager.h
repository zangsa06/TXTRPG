#pragma once
#include "Player.h"
#include "Monster.h"
#include "Boss.h"

class Game
{
public:
	Player player;
	int floor;
	Game();
	void Run();
	Monster* CreateMonster(int floor);
	Boss* CreateBoss(int floor);
};
