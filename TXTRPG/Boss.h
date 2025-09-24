#pragma once
#include "Monster.h"

class Boss : public Monster
{
public:
	Boss(std::string name, int floor, MonsterType type);

	void SpecialSkill();
};

