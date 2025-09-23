#pragma once
class Game
{
public:
	Game() : floor(1), CurrentWeapon(Sword)
	{
		srand((unsigned)time(0));
	}
	void run();

protected:
	Player player;
	int floor = 1;
	WeaponType CurrentWeapon;
	int WeaponEffect(WeaponType w, Monster m);

	void BossEnter(const std::string& BossName, int HP, int Attack, int Defense);
	Monster* CreateMonster(int floor);

	void ChooseWeapon(Monster* m);

	bool Battle(Monster* m);
};

