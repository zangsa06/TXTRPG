#pragma once
class Player
{
public:
	Player()
		: HP(100), MaxHP(100), Attack(10), Defense(5), DropGold(0), Exp(0), Level(1), PowerStrike(false), Shield(false) {
	}
	int GetHP() { return HP; }
	int GetAttack() { return Attack; }
	int GetDefense() { return Defense; }
	int GetDropGold() { return DropGold; }
	int GetLevel() { return Level; }
	bool IsAlive() { return HP > 0; }

	void TakeDamage(int Damage);
	void Heal(int Amount);

	void AddGold(int gold) { DropGold += gold; }
	void SpendGold(int gold);
	void AddExp(int exp);
	void AddItem(const Item& item);

	void ShowStatus();

	void UseSkill();

	int AttackMonster(int BaseAttack, Monster* m, int WeaponMultiply);

protected:
	int HP = 100;
	int MaxHP = 100;
	int Attack = 10;
	int Defense = 5;
	int Gold = 0;
	int Exp = 0;
	int Level = 1;
	std::vector<Item> Inventory;
	bool PowerStrike;
	bool Shield;
};

