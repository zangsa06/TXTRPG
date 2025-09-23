#pragma once
#include "Monster.h"

class Boss : public Monster
{
public:
	Boss(int floor);

	int AttackPattern(int PlayerDef);


};

