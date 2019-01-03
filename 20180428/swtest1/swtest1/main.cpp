#include<stdio.h>
#pragma warning(disable: 4996)
int T;
int map_x, map_y, current_x, current_y;
int map[512][512];//장애물=-1,각 칸에는 점수(숫자)가 들어가고 한번 지나가면 해당칸의 점수 지워짐
int command_count;
int spinner[8];
int spinner_location;
int spinner_box;
int collected = 0;
void preset()//초기화
{
	collected = 0;
	for (int i = 0; i < 512; i++)
		for (int j = 0; j < 512; j++)
			map[i][j] = 0;
	for (int i = 0; i <= map_x + 1; i++)
		map[i][map_y + 1] = map[i][0] = -1;
	for (int i = 0; i <= map_y + 1; i++)
		map[map_x + 1][i] = map[0][i] = -1;
	command_count = 0;
	for (int i = 0; i < 8; i++)
		spinner[i] = 0;
	spinner_location = 0;
}
int spinner_spin(int direction, int count)
{
	if (direction == 1)//시계방향
	{
		spinner_location += count;
		spinner_location %= spinner_box;
	}
	else
	{
		for (int i = 0; i < count%spinner_box; i++)
		{
			if (spinner_location == 0)
				spinner_location += spinner_box;
			spinner_location--;
		}
	}
	return spinner[spinner_location];
}
void MOVE(char direction, int move_count)
{
	if (direction == 'N')
	{
		for (int i = 0; i < move_count; i++)
		{
			if (map[current_x][current_y - 1] == -1)
				break;
			else
			{
				collected += map[current_x][current_y];
				map[current_x][current_y] = 0;
				current_y--;
			}
		}
	}
	else if (direction == 'S')
	{
		for (int i = 0; i < move_count; i++)
		{
			if (map[current_x][current_y + 1] == -1)
				break;
			else
			{
				collected += map[current_x][current_y];
				map[current_x][current_y] = 0;
				current_y++;
			}
		}
	}
	else if (direction == 'E')
	{
		for (int i = 0; i < move_count; i++)
		{
			if (map[current_x + 1][current_y] == -1)
				break;
			else
			{
				collected += map[current_x][current_y];
				map[current_x][current_y] = 0;
				current_x++;
			}
		}
	}
	else
	{
		for (int i = 0; i < move_count; i++)
		{
			if (map[current_x - 1][current_y] == -1)
				break;
			else
			{
				collected += map[current_x][current_y];
				map[current_x][current_y] = 0;
				current_x--;
			}
		}
	}
}
int main()
{
	char dirr;
	int spin_count;
	int spin_dir;
	int move_cnt;
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf_s("%d%d%d%d", &map_x, &map_y, &current_x, &current_y);
		preset();
		for (int i = 1; i <= map_y; i++)
		{
			for (int j = 1; j <= map_x; j++)
			{
				scanf_s("%d", &map[j][i]);
			}
		}
		scanf_s("%d", &spinner_box);
		for (int i = 0; i < spinner_box; i++)
			scanf_s("%d", &spinner[i]);
		scanf_s("%d", &command_count);
		for (int i = 0; i < command_count; i++)
		{
			scanf_s("%c %d %d", &dirr, &spin_dir, &spin_count);
			move_cnt = spinner_spin(spin_dir, spin_count);
			MOVE(dirr, move_cnt);
		}
		collected += map[current_x][current_y];
		printf("#%d %d %d %d\n", T, collected, current_x, current_y);
	}
}