#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>
#include<windows.h>

#define chance 5

int main()
{
	int randnum[3], scannum[3];
	int maxStrike = 0, maxBall=0;
	int strike, ball;
	int i, j;
	int cnt = 0;

	srand(time(NULL));

	for (i = 0; i < 3; i++) {
		randnum[i] = rand() % 9 + 1;
		for (j = 0; j < i; j++) {
			if (randnum[i] == randnum[j]) {
				i--;
				break;
			}
		}
	}
	while (1)
	{
		strike = ball = 0;
		cnt++;
		printf("%d번 남았습니다.\n", chance + 1 - cnt);
		printf("숫자 3개를 입력하세요 : ");
		scanf_s("%d %d %d", &scannum[0], &scannum[1], &scannum[2]);
		if ((scannum[0] == scannum[1]) || (scannum[1] == scannum[2]) || (scannum[0] == scannum[2]))
		{
			printf("숫자중복을 허용하지 않습니다. 다시...\n");
			printf("-----------------------------------\n");
			cnt--;
			continue;
		}
		if (scannum[0] == 0 || scannum[1] == 0 || scannum[2] == 0)
		{
			printf("0이외의 다른 숫자를 써주세요. 다시...\n");
			printf("-----------------------------------\n");
			cnt--;
			continue;
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (randnum[i] == scannum[j] && i == j)
					strike++;
				if (randnum[i] == scannum[j] && i != j)
					ball++;
			}
		}
		if (strike > maxStrike)
		{
			maxStrike = strike;
			maxBall = ball;
		}
		if (ball > maxBall&&maxStrike < ball)
		{
			maxStrike = strike;
			maxBall = ball;
		}
		if (strike == 3)
		{
			system("cls");
			printf("\n\n\n\n");
			printf("\t게임 승리!    ");
			printf("정답을 맞추었습니다.\n");
			printf("    ---------이번 게임의 최고기록은---------\n");
			printf("\t%d 스트라이크  \t%d 볼   입니다.", maxStrike, maxBall);
			printf("\n\n        축하드려요!");
			break;
		}
		printf("%d 스트라이크 %d 볼입니다.\n", strike, ball);
		printf("-----------------------------------\n");
		if (cnt == chance)
		{
			system("cls");
			printf("\n\n\n\n");
			printf("\t게임 패배!\n");
			printf("    ---------이번 게임의 최고기록은---------\n");
			printf("\t%d 스트라이크  \t%d 볼   입니다.", maxStrike, maxBall);
			break;
		}
	}
	_getch();
}