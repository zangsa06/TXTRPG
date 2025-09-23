#include "Boss.h"
#include <iostream>

Boss::Boss(int floor)
{
	Boss(int floor) : Monster(static_cast<MonsterType>(rand() % MonsterCount), floor)
	{
		switch (floor)
		{
		case 10:
			name = "Warden";
			break;
		case 20:
			name = "Lich King";
			break;
		case 30:
			name = "Stone Golem";
			break;
		case 40:
			name = "Dragon";
			break;
		case 50:
			name = "Tower Guardian";
			break;
		default:
			name = "Unknown";
			break;
		}
		HP = static_cast<int>(HP * 2.0);
		Attack = static_cast<int>(Attack * 1.5);
		Defense = static_cast<int>(Defense * 1.5);
		DropGold *= 3;
		DropExp *= 3;
	}
}

int Boss::AttackPattern(int PlayerDef)
{
	int Damage = 0;
	int Choice = rand() % 100;

	if (name == "Warden" && HP < 50)
	{
		printf("파수꾼이 강력한 공격을 합니다.\n");
		Damage = (Attack - PlayerDef) * 2.0;
	}
	return Damage;
}
