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
		printf("%d�� ���ҽ��ϴ�.\n", chance + 1 - cnt);
		printf("���� 3���� �Է��ϼ��� : ");
		scanf_s("%d %d %d", &scannum[0], &scannum[1], &scannum[2]);
		if ((scannum[0] == scannum[1]) || (scannum[1] == scannum[2]) || (scannum[0] == scannum[2]))
		{
			printf("�����ߺ��� ������� �ʽ��ϴ�. �ٽ�...\n");
			printf("-----------------------------------\n");
			cnt--;
			continue;
		}
		if (scannum[0] == 0 || scannum[1] == 0 || scannum[2] == 0)
		{
			printf("0�̿��� �ٸ� ���ڸ� ���ּ���. �ٽ�...\n");
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
			printf("\t���� �¸�!    ");
			printf("������ ���߾����ϴ�.\n");
			printf("    ---------�̹� ������ �ְ�����---------\n");
			printf("\t%d ��Ʈ����ũ  \t%d ��   �Դϴ�.", maxStrike, maxBall);
			printf("\n\n        ���ϵ����!");
			break;
		}
		printf("%d ��Ʈ����ũ %d ���Դϴ�.\n", strike, ball);
		printf("-----------------------------------\n");
		if (cnt == chance)
		{
			system("cls");
			printf("\n\n\n\n");
			printf("\t���� �й�!\n");
			printf("    ---------�̹� ������ �ְ�����---------\n");
			printf("\t%d ��Ʈ����ũ  \t%d ��   �Դϴ�.", maxStrike, maxBall);
			break;
		}
	}
	_getch();
}