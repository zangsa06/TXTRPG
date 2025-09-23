#pragma once

class Monster
{
public:
	MonsterType type;
	Monster(MonsterType t, int floor) : type(t)
	{
		static const char* names[] = { "짐승", "언데드", "인간형", "정령", "골렘" };
		name = names[t];
		HP = 20 + floor * 2 + rand() % 10;
		Attack = 5 + floor / 2 + rand() % 3;
		DropGold = 5 + floor + rand() % 5;
		DropExp = 10 + floor * 2;
	}
	virtual ~Monster() {}
	virtual std::string GetName() { return name; }
	virtual int GetHP() { return HP; }
	virtual int GetAttack() { return Attack; }
	virtual int GetDefense() { return Defense; }
	virtual int GetDropGold() { return DropGold; }
	virtual int GetDropExp() { return DropExp; }
	virtual void TakeDamage(int Damage)
	{
		HP -= Damage;
	}
	bool IsAlive() { return HP > 0; }
	MonsterType GetType() { return type; }

protected:
	std::string name;
	int HP = 0;
	int Attack = -1;
	int Defense = -1;
	int DropGold = -1;
	int DropExp = -1;
};

