#include "Player.h"
#include <cstdio>
#include <iostream>

void TakeDamage(int Damage)
{
	if (Shield)
	{
		Damage /= 2;
		Shield = false;
		printf("방어 강화로 피해 절반 감소\n");
	}
	HP -= Damage;
}

void Heal(int Amount)
{
	HP += Amount;
	if (HP > MaxHP)
	{
		HP = MaxHP;
	}
}

void SpendGold(int gold)
{
	if (DropGold >= gold)
	{
		DropGold -= gold;
	}
}

void AddExp(int exp)
{
	DropExp += exp;
	int Require = 50 * Level;
	if (DropExp >= Require)
	{
		Level++;
		DropExp -= Require;
		printf("레벨업\n현재 레벨 : %d", Level);
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
	}
}

void AddItem(const Item& item)
{
	Inventory.push_back(item);
	printf("아이템 획득 : [%s][%s]\n", item.name, item.effect);
}

void ShowStatus()
{
	printf("[레벨 %d]\n체력 : %d/%d\n공격 : %d\n방어 : %d\n골드 소지금 : %d\n현재 경험치 : %d\n", Level, HP, MaxHP, Defense, DropGold, DropExp);
}

void UseSkill()
{
	printf("사용할 스킬 선택\n1. 강타\n2. 방어\n3. 회복\n");
	int Choice = 0;
	std::cin >> Choice;
	switch (Choice)
	{
	case 1:
		PowerStrike = true;
		printf("다음 공격이 2배의 피해를 입힙니다.\n");
		break;
	case 2:
		Shield = true;
		printf("다음 턴에 받는 피해가 절반으로 감소합니다.\n");
		break;
	case 3:
		Heal(30);
		printf("즉시 체력 30 회복\n");
		break;
	default:
		printf("스킬 취소\n");
		break;
	}
}

int AttackMonster(int BaseAttack, Monster* m, int WeaponMultiply)
{
	int Damage = (BaseAttack - m->GetDefense()) * WeaponMultiply;
	if (PowerStrike)
	{
		Damage * 2;
		PowerStrike = false;
		printf("피해가 2배로 적용됩니다.\n");
	}
	return Damage;
}


