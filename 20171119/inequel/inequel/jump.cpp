#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define player |

int player_gravity = 1;
char name[20];
struct bg
{
	int code = 0;//0=�����,1=������Ʈ(������,���),2=�����(�����),3=�߶���(�ٸ���)
	int length = 0;//3~5ĭ(������Ʈ)
	bool stat = false;//(����/�ٴ�)
};
bg map[80][25];
BOOL gotoxy(int x, int y)
{
	COORD pos;   //short Ÿ���� X, Y �Ӽ��� ��� �ִ� ����ü�̴�.
	pos.X = x;
	pos.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void SetCursor_hide()
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false; // true ����, false �Ⱥ���
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // ����
}
void SetCursor_show()
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = true; // true ����, false �Ⱥ���
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // ����
}
void get_name()
{
	gotoxy(19, 11);
	SetCursor_show();
	printf("Let me know your NAME : ");
	gets_s(name);
	gotoxy(19, 11);
	for (int i = 0; i < 40; i++)
		printf(" ");
	gotoxy(29, 11);
	printf("Welcome %s.", name);
	Sleep(1000);
	system("cls");
}
void set()
{
	system("mode con cols=80 lines=25");
	system("title Jump");
	system("color 1e");
	for (int i = 0; i < 90; i++)
		for (int j = 0; j < 30; j++)
			map[i][j] = 0;
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 25; j++)
			printf(" ");
		printf("\n");
	}
	SetCursor_hide();
	get_name();
}
void gravity()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (map[j][i].code == 2 && map[j][i].stat == true)
			{
				map[j][i + 1] = map[j][i];
				map[j][i].code = 0;
				map[j][i].length = 0;
				map[j][i].stat = false;
			}
		}
	}
}
void get_started()
{
	system("cls");
	system("color f0");
	Sleep(700);
	system("color 1e");
}
int main()
{
	bool k = false;
	srand(time(NULL));
	set();
	gotoxy(29, 11);
	printf("Now Loading...");
	system("cls");
	Sleep(500);
	SetCursor_hide();
	while (1)
	{
		gotoxy(1, 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 80; j++)
			{
				int a = rand() % 2;
				printf("%d", a);
			}
			printf("\n");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		gotoxy(29, 9);
		printf("Loading Complete!");
		gotoxy(29, 16);
		printf("[PRESS ANY KEY]");
		for (int i = 0; i < 50; i++)
		{
			Sleep(10);
			if (_kbhit())
			{
				k = true;
				break;
			}
		}
		if (k == true)
			break;
	}
	get_started();
	_getch();
}