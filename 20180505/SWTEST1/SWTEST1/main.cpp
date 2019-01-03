#include<stdio.h>
#pragma warning(disable: 4996)
int T, N, M, map[16][16];
int max_route = 0;
int route_cnt = 0;
int passed[300];
int sum;
/*int map_custum[16][16];

typedef struct _student {
	int x[150];
	int y[150];
	int top = 0;
} juso;

juso list[256];
int f(int xx, int yy)
{
	
	if (map_custum[xx + 1][yy] != -1)
	{

		f(xx + 1, yy);

	}
	if (map_custum[xx][yy + 1] != -1)
	{
		f(xx, yy + 1);
	}
}*/
void pre_set()
{
	max_route = 0;
	route_cnt = 0;
	for (int i = 0; i < 300; i++)
		passed[i] = 0;
}
void f(int xx, int yy)
{
	if (xx == M - 1 && yy == N - 1)
	{
		sum = 0;
		for (int i = 0; i < 300; i++)
		{
			if (passed[i] == 1)
				sum += i;
		}
		if (max_route < sum)
			max_route = sum;
		route_cnt++;
	}
	if (passed[map[xx + 1][yy]] != 1)
	{
		passed[map[xx + 1][yy]] = 1;
		f(xx + 1, yy);
		passed[map[xx + 1][yy]] = 0;
	}
	if (passed[map[xx][yy + 1]] != 1)
	{
		passed[map[xx][yy + 1]] = 1;
		f(xx, yy + 1);
		passed[map[xx][yy + 1]] = 0;
	}
	return;
}
int main()
{
	scanf("%d", &T);
	for (int zzzz = 0; zzzz < T; zzzz++)
	{
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &map[j][i]);
		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				list[map[j][i]].x[list[map[j][i]].top] = j;
				list[map[j][i]].y[list[map[j][i]].top++] = i;
			}
		}
		if (map[M - 1][N - 1] == map[0][0])
		{
			printf("#%d 0 -1\n", zzzz + 1);
			return 0;
		}*/
		passed[map[0][0]] = 1;
		printf("#%d %d %d\n", zzzz + 1, route_cnt, max_route);
	}
 	while (1);
}