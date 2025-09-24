#include "Player.h"
#include <cstdio>
#include <iostream>

Player::Player(std::string name)
{
	Name = name;
	Level = 1;
	MaxHP = 100;
	HP = 100;
	Attack = 10;
	Defense = 5;
	Exp = 0;
	Soul = 0;
	Shield = false;
	Weapon = Sword;
}
void Player::TakeDamage(int Damage)
{
	if (Shield)
	{
		Damage /= 2;
		Shield = false;
		printf("방어 강화로 피해 절반 감소\n");
	}
	HP -= Damage;
	if (HP < 0)
	{
		HP = 0;
	}
}

void Player::Heal(int Amount)
{
	HP += Amount;
	if (HP > MaxHP)
	{
		HP = MaxHP;
	}
}

void Player::Spend(int soul)
{
	if (Soul >= soul)
	{
		Soul -= soul;
	}
}

void Player::AddExp(int exp)
{
	Exp += exp;
	int Require = 50 * Level;
	printf("현재 경험치 : %d\n", Exp);
	if (Exp < Require)
	{
		printf("레벨업까지 남은 경험치 : % d\n", Require - Exp);
	}
	else if (Exp >= Require)
	{
		Level++;
		Exp -= Require;
		printf("레벨업\n현재 레벨 : %d\n잔여 경험치 : %d\n", Level, Exp);
		int Point = Level;
		while (Point > 0)
		{
			printf("포인트를 사용하세요\n현재 포인트 : %d\n1. 체력\n2. 공격력\n3. 방어력\n", Point);
			int Choice = 0;
			std::cin >> Choice;
			if (Choice == 1)
			{
				MaxHP += 10;
				HP += 10;
			}
			else if (Choice == 2)
			{
				Attack += 2;
			}
			else if (Choice == 3)
			{
				Defense += 2;
			}
			Point--;
		}
		HP = MaxHP;
		printf("현재 체력\t: %d\n", MaxHP);
		printf("현재 공격력\t: %d\n", Attack);
		printf("현재 방어력\t: %d\n", Defense);
	}
}

void Player::AttackMonster(Monster* m)
{
	int Damage = Attack - m->Defense;
	if (Damage < 1)
	{
		Damage = 1;
	}
	if ((Weapon == Sword && m->Type == Undead)
		|| (Weapon == Spear && m->Type == Giant)
		|| (Weapon == Bow && m->Type == Beast))
	{
		Damage *= 2;
		printf("상성인 무기로 2배의 피해를 입힙니다.\n");
	}
	m->HP -= Damage;
	std::cout << m->Name << "(이)가 " << Damage << "의 피해를 입습니다.\n";
	if (m->HP < 0)
	{
		m->HP = 0;
	}
	std::cout << m->Name << "의 현재 체력 : " << m->HP << "\n";
}
