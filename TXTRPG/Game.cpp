#include "Game.h"

void run()
{
	while (floor <= 50 && player.IsAlive())
	{
		std::cout << "\n-- " << floor << "층 --\n";
		Monster* m = CreateMonster(floor);
		bool Clear = Battle(m);
		delete m;
		if (Clear)
		{
			floor++;
		}
		else if (!player.IsAlive())
		{
			break;
		}
	}
	if (player.IsAlive())
	{
		printf("타워를 정복했습니다\n");
	}
	else
	{
		printf("게임 오버\n");
	}
}

int WeaponEffect(WeaponType w, Monster m)
{
	if (w == Sword && m == Undead)
	{
		return 2;
	}
	if (w == Sword && m == Best)
	{
		return 2;
	}
	if (w == Bow && m == Humanoid)
	{
		return 2;
	}
	return 1;
}

void BossEnter(const std::string& BossName, int HP, int Attack, int Defense)
{
	printf("-----------보스 등장-----------\n%s\n[체력 : %d | 공격력 : %d | 방어력 : %d ]\n전투를 준비하세요\n", BossName, HP, Attack, Defense);
}

Monster* CreateMonster(int floor)
{
	if (floor % 10 == 0)
	{
		Boss* boss = new Boss(floor);
		BossEnter(boss->GetName(), boss->GetHP(), boss->GetAttack(), boss->GetDefense());
		return boss;
	}
	return new Monster(static_cast<MonsterType>(rand() % MonsterCount, floor);
}

void ChooseWeapon(Monster* m)
{
	printf("%s에게 맞설 무기를 선택하세요\n1. 검\n2. 창\n3. 활\n", m->GetName());
	int Choice = 0;
	std::cin >> Choice;
	CurrentWeapon = static_cast<WeaponType>(Choice - 1);
}

bool Battle(Monster* m)
{
	ChooseWeapon(m);
	while (m->IsAlive() && player.IsAlive())
	{
		player.ShowStatus();
		printf("[%s] 체력 : %d\n", m->GetName(), m->GetHP());
		printf("행동 선택\n1. 공격\n2. 회복\n3. 도망\n 4.스킬\n");
		int Choice = 0;
		std::cin >> Choice;
		if (Choice == 1)
		{
			int Damage = player.AttackMonster(player.GetAttack(), m, WeaponEffect(CurrentWeapon, m->GetType()));
			m->TakeDamage(Damage);
			printf("당신이 %d의 피해를 주었습니다.\n", Damage);
		}
		else if (Choice == 2)
		{
			if (player.GetDropGold() >= 5)
			{
				player.SpendGold(5);
				player.Heal(20);
				printf("5골드를 소모하여 체력을 20회복합니다.\n");
			}
			else
			{
				printf("골드가 부족합니다.\n");
			}
		}
		else if (Choice == 3)
		{
			if (floor > 1)
			{
				floor--;
				printf("한 층 아래로 도망쳤습니다. 현재 층 : %d\n", floor);
				delete m;
				return false;
			}
			else
			{
				printf("1층에서는 도망칠 수 없습니다.\n");
			}
		}
		else if (Choice == 4)
		{
			player.UseSkill();
		}
		if (m->IsAlive())
		{
			int Damage = 0;
			Boss* boss = dynamic_cast<Boss*>(m);
			if (boss)
			{
				Damage = boss->AttackPattern(player.GetDefense());
			}
			else
			{
				Damage = m->GetAttack() - player.GetDefense();
				printf("[%s]에게 %d의 피해를 입었습니다.\n", m->GetName(), Damage);
			}
			player.TakeDamage(Damage);
		}
	}
	if (player.IsAlive())
	{
		printf("[%s](을)를 처치했습니다.\n");
		player.AddGold(m->GetDropGold());
		player.AddExp(m->GetDropExp());
		if (floor % 10 == 0)
		{
			switch (floor)
			{
			case 10:
				player.AddItem(Item("붉은 호박 메달리온", "체력 +20"));
				break;
			case 20:
				player.AddItem(Item("알렉산더의 파편", "공격 +5"));
				break;
			case 30:
				player.AddItem(Item("대형 방패의 탈리스만", "방어 +5"));
				break;
			case 40:
				player.AddItem(Item("축복의 인도", "1회 부활 가능"));
				break;
			case 50:
				player.AddItem(Item("신이 남긴 검", "최종 보상"));
				break;
			}
		}
		return true;
	}
	return false;
}
