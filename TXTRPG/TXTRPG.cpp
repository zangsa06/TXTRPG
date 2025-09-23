enum MonsterType { Beast, Undead, Humanoid, Elemental, Construct, MonsterCount };
enum WeaponType { Sword, Spear, Bow, WeaponCount };

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>
#include "TXTRPG.h"
#include "Monster.h"
#include "Boss.h"
#include "Game.h"
#include "Player.h"
#include "Item.h"

int main()
{
	Game game;
	game.run();

	return 0;
}
