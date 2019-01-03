#include<stdio.h>
int T;
int map[16][16];
int m, n;//n:세로,m:가로
int chk[216];
int max_road = 0, road_cnt = 0;

void pre_set()
{
	max_road = road_cnt = 0;
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
			map[i][j] = 0;
	for (int i = 0; i < 216; i++)
		chk[i] = 0;
}
int find_road(int x, int y)
{
	int sum = 0;
	if (x == m - 1 && y == n - 1)
	{
		for (int i = 0; i < 211; i++)
			if (chk[i] == 1)
				sum += i;
		if (max_road < sum)
			max_road = sum;
		road_cnt++;
		return 0;
	}
	if (chk[map[x + 1][y]] == 0 && x < m)
	{
		chk[map[x + 1][y]]++;
		find_road(x + 1, y);
		chk[map[x + 1][y]]--;
	}
	if (chk[map[x][y + 1]] == 0 && y < n)
	{
		chk[map[x][y + 1]]++;
		find_road(x, y + 1);
		chk[map[x][y + 1]]--;
	}
	return 0;
}
int main()
{
	scanf("%d", &T);
	for (int zzz = 1; zzz <= T; zzz++)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &map[j][i]);
			}
		}
		chk[map[0][0]]++;
		find_road(0, 0);
		if (road_cnt == 0 && max_road == 0)
			printf("#%d 0 -1\n",zzz);
		else
			printf("#%d %d %d\n", zzz, road_cnt, max_road);
		pre_set();
	}
	//while (1);
}