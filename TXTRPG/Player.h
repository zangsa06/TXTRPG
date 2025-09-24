#pragma once
#include <vector>
#include <string>
#include "TXTRPG.h"
#include "Monster.h"

class Player
{
public:
	std::string Name;
	int Level;
	int HP;
	int MaxHP;
	int Attack;
	int Defense;
	int Exp;
	int Soul;
	bool Shield;
	WeaponType Weapon;
	Player(std::string name);
	void TakeDamage(int Damage);
	void Heal(int Amount);
	void Spend(int soul);
	void AddExp(int exp);
	void AttackMonster(Monster* m);
	bool IsAlive() const { return HP > 0; }
};

