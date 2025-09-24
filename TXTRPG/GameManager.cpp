#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game() : player("플레이어"), floor(1)
{
	srand((unsigned)time(0));
}

Monster* Game::CreateMonster(int floor)
{
	std::string Names[] = { "늑대", "해골병사", "숭배자", "슬라임", "거인" };
	MonsterType type = (MonsterType)(rand() % MonsterCount);
	return new Monster(Names[type], floor, type);
}

Boss* Game::CreateBoss(int floor)
{
	std::string BossNames[] = { "타워가드", "비룡", "군주", "화신", "수호자" };
	int index = (floor / 10 - 1) % 5;
	return new Boss(BossNames[index], floor, (MonsterType)(rand() % MonsterCount));
}

void Game::Run()
{
	while (floor <= 50 && player.IsAlive())
	{
		std::cout << "\n--- " << floor << "층 ---\n";
		Monster* m;
		if (floor % 10 == 0)
		{
			m = CreateBoss(floor);
			std::cout << "보스" << m->Name << "(이)가 나타났습니다.\n";
		}
		else
		{
			m = CreateMonster(floor);
			std::cout << m->Name << "(이)가 나타났습니다.\n";
		}
		printf("무기를  선택하세요.\n[1] 검 [2] 창 [3] 활\n");
		int Choice = 0;
		std::cin >> Choice;
		if (Choice == 1)
		{
			WeaponType myWeapon = Sword;
			printf("검을 무기로 선택했습니다.\n");
		}
		else if (Choice == 2)
		{
			WeaponType myWeapon = Spear;
			printf("창을 무기로 선택했습니다.\n");
		}
		else if (Choice == 3)
		{
			WeaponType myWeapon = Bow;
			printf("활을 무기로 선택했습니다.\n");
		}
		while (m->IsAlive() && player.IsAlive())
		{
			printf("\n[1] 공격 [2] 방어 [3] 회복(20) [4] 도망\n");
			int Choice = 0;
			std::cin >> Choice;

			if (Choice == 1)
			{
				player.AttackMonster(m);
			}
			else if (Choice == 2)
			{
				player.Shield = true;
				printf("방어를 합니다.\n");
			}
			else if (Choice == 3)
			{
				if (player.Soul >= 20)
				{
					player.Spend(20);
					player.Heal(player.MaxHP / 2);
					printf("체력을 %d 회복했습니다.\n", player.MaxHP / 2);
				}
				else
				{
					printf("골드가 부족합니다.\n");
				}
			}
			else if (Choice == 4)
			{
				printf("도망쳤습니다. 한 층 아래로 내려갑니다.\n");
				if (floor > 1)
				{
					floor--;
				}
				else if (floor <= 1)
				{
					printf("1층에서는 도망칠 수 없습니다.\n");
				}
			}
			if (m->IsAlive())
			{
				int Damage = m->AttackPlayer() - player.Defense;
				if (Damage < 1)
				{
					Damage = 1;
				}
				player.TakeDamage(Damage);
				std::cout << m->Name << "의 공격에 " << Damage << "의 피해를 입었습니다.(현재 체력 : " << player.HP << ")\n";
			}
		}
		if (player.IsAlive())
		{
			std::cout << m->Name << "(을)를 쓰러뜨렸습니다.\n";
			printf("경험치 %d(와)과 골드 %d(을)를 획득했습니다.\n", m->DropExp, m->DropSoul);
			player.Soul += m->DropSoul;
			printf("현재 소지금 : %d\n", player.Soul);
			player.AddExp(m->DropExp);
			floor++;
		}
		delete m;
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
