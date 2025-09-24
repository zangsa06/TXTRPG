#include "Boss.h"
#include <cstdio>
#include <cstdlib>

Boss::Boss(std::string name, int floor, MonsterType type)
	: Monster(name, floor, type)
{
	MaxHP *= 2;
	HP = MaxHP;
	Attack += 10;
	Defense += 5;
	DropExp *= 3;
	DropSoul *= 3;
}

void Boss::SpecialSkill()
{
	int Possib = rand() % 1;
	if (Possib == 0)
	{
		printf("%s의 공격력이 두 배 오릅니다.\n", Name.c_str());
		Attack *= 2;
	}
	else if (Possib == 1)
	{
		int heal = MaxHP / 4;
		HP += heal;
		if (HP > MaxHP)
		{
			HP = MaxHP;
		}
		printf("%s가 체력을 회복합니다. +%d HP\n", Name.c_str(), heal);
	}
}
	