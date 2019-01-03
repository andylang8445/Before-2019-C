#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#pragma warning(disable: 4996)
int T;
int map_x, map_y, current_x, current_y;
int destination_x, destination_y;
int map[16][16];
int road_count = 0, max_road = 0;
int cmp[256];
bool x_ok = true;
bool y_ok = true;
void pre_set()
{
	road_count = max_road = 0;
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
			map[i][j] = -1;
	current_x = current_y = 1;
	destination_x = map_x;
	destination_y = map_y;
}
void find_road(int x, int y, int sum, int passed)
{
	x_ok = y_ok = true;
	cmp[passed] = map[x][y];
	if (x > map_x || y > map_y)
		return;
	if (x == map_x && y == map_y)
	{
		sum += map[x][y];
		road_count++;
		if (max_road < sum)
			max_road = sum;
		for (int i = 0; i < passed; i++)
			printf("%3d", cmp[i]);
		printf("\n");
	}
	for (int i = 0; i <= passed; i++)
	{
		if (cmp[i] == map[x + 1][y])
			x_ok = false;
		if (cmp[i] == map[x][y + 1])
			y_ok = false;
	}
	if(x_ok)
		find_road(x + 1, y, sum + map[x][y], passed + 1);
	if(y_ok)
		find_road(x, y + 1, sum + map[x][y], passed + 1);
}
int main()
{
	scanf("%d", &T);
	for (int zzzz = 0; zzzz < T; zzzz++)
	{
		scanf("%d%d", &map_y, &map_x);
		pre_set();
		for (int i = 1; i <= map_y; i++)
		{
			for (int j = 1; j <= map_x; j++)
				scanf("%d", &map[j][i]);
		}
		find_road(current_x, current_y, 0, 0);
		//if(road_count>0)
			printf("#%d %d %d\n", zzzz + 1, road_count, max_road);
		/*else
			printf("#%d 0 -1\n", zzzz + 1);*/
	}
	while (1);
}