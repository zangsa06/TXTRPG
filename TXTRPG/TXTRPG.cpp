#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>
#include "TXTRPG.h"
#include "Monster.h"
#include "Boss.h"
#include "GameManager.h"
#include "Player.h"

int main()
{
	printf("텍스트RPG를 시작합니다.\n");
	printf("몬스터를 잡아 경험치와 영혼을 획득할 수 있습니다.\n");
	printf("경험치는 능력치 상승에, 영혼은 체력 회복에 사용할 수 있습니다.\n");
	printf("타워에 입장합니다.\n");
	Game game;
	game.Run();

	return 0;
}
