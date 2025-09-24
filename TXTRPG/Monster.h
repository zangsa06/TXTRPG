#pragma once
#include <string>
#include "TXTRPG.h"

class Monster
{
public:
	std::string Name;
	int HP;
	int MaxHP;
	int Attack;
	int Defense;
	int DropExp;
	int DropSoul;
	MonsterType Type;
	Monster(std::string name, int floor, MonsterType type);
	virtual ~Monster()
	{
	}
	virtual void TakeDamage(int Damage);
	virtual int AttackPlayer();
	bool IsAlive() const { return HP > 0; }
};

