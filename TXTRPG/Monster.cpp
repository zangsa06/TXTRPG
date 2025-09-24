#include "Monster.h"
#include <cstdlib>

Monster::Monster(std::string name, int floor, MonsterType type)
{
	Name = name;
	MaxHP = 30 + floor * 3;
	HP = MaxHP;
	Attack = 5 + floor * 3;
	Attack = 5 + floor * 2;
	Defense = 2 + floor / 2;
	DropExp = 10 + floor * 3;
	DropSoul = 5 + floor * 5;
	Type = type;
}

void Monster::TakeDamage(int Damage)
{
	HP -= Damage;
	if (HP < 0)
	{
		HP = 0;
	}
}
int Monster::AttackPlayer()
{
	return Attack;
}
