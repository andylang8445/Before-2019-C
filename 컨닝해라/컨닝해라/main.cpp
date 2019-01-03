#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<iostream>
#define COL                   GetStdHandle(STD_OUTPUT_HANDLE)        // 콘솔창의 핸들정보 받기
#define SKY_BLUE           SetConsoleTextAttribute(COL, 0x000b);        // 하늘색
#define GREEN                SetConsoleTextAttribute(COL, 0x0002);        // 녹색
#define YELLOW             SetConsoleTextAttribute(COL, 0x000e);        // 노란색
#define RED                   SetConsoleTextAttribute(COL, 0x000c);        // 빨간색
#define ORIGINAL            SetConsoleTextAttribute(COL, 0x0007);        // 밝은 회색 (ORIGINAL CONSOLE COLOR)
#define BLOOD               SetConsoleTextAttribute(COL, 0x0004);        // 검붉은색
#define height 38
#define width 60
#define check_width PX+1==TX&&PY==TY||PX+2==TX&&PY==TY||PX+3==TX&&PY==TY||PX+4==TX&&PY==TY||PX==TX&&PY==TY||PX-4==TX&&PY==TY||PX-1==TX&&PY==TY||PX-2==TX&&PY==TY||PX-3==TX&&PY==TY||exPX+1==exTX&&exPY==exTY||exPX+2==exTX&&exPY==exTY||exPX+3==exTX&&exPY==exTY||exPX+4==exTX&&exPY==exTY||exPX==exTX&&exPY==exTY||exPX-4==exTX&&exPY==exTY||exPX-1==exTX&&exPY==exTY||exPX-2==exTX&&exPY==exTY||exPX-3==exTX&&exPY==exTY
#define check_height PX==TX&&PY+1==TY||PX==TX&&PY+2==TY||PX==TX&&PY+3==TY||PX==TX&&PY-1==TY||PX==TX&&PY-2==TY||PX==TX&&PY-3==TY||exPX==exTX&&exPY+1==exTY||exPX==exTX&&exPY+2==exTY||exPX==exTX&&exPY+3==exTY||exPX==exTX&&exPY-1==exTY||exPX==exTX&&exPY-2==exTY||exPX==exTX&&exPY-3==exTY
#define TX_origin 30
#define TY_origin 1
#define PX_origin 34
#define PY_origin 22
int map[height][width], TX = TX_origin, TY = TY_origin, PX = PX_origin, PY = PY_origin, exPX, exPY, hp = 3, cnty = 0, cntx = 0, combo = 0;
int exTX = TX, exTY = TY, score = 0, arrive = 0;
void gotoxy(int xxx, int yyy)  //x,y순서로 입력, 커서 이동(배열 좌표아닌 실제 좌표) 
{
	COORD pos = { xxx, yyy };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void target()
{
	srand(time(NULL));
	int rx, ry;
	while (1)
	{
		rx = rand() % (width - 1);
		ry = rand() % (height - 1);
		if (map[ry][rx] == 0)
		{
			map[ry][rx] = 5;
			break;
		}
	}
}
void target_family()
{
	srand(time(NULL));
	int rx, ry;
	while (1)
	{
		rx = rand() % (width - 1);
		ry = rand() % (height - 1);
		if (map[ry][rx] == 0)
		{
			map[ry][rx] = 5;
			break;
		}
	}
	gotoxy(rx, ry);
	printf("#");
}
void set()
{
	for (int i = 0; i<height; i++)
		for (int j = 0; j<width; j++)
			map[i][j] = 0;
	for (int i = 0; i<width; i++)
		map[0][i] = map[height - 1][i] = 1;
	for (int i = 0; i<height; i++)
		map[i][0] = map[i][width - 1] = 1;
	for (int i = 24; i<37; i++)
		map[6][i] = map[2][i] = 3;
	for (int i = 3; i<6; i++)
		for (int j = 25; j<36; j++)
			map[i][j] = 4;
	map[3][24] = 2;
	map[4][24] = 2;
	map[5][24] = 2;
	map[4][27] = 'T';
	map[4][28] = 'E';
	map[4][29] = 'A';
	map[4][30] = 'C';
	map[4][31] = 'H';
	map[4][32] = 'E';
	map[4][33] = 'R';
	map[3][36] = 2;
	map[4][36] = 2;
	map[5][36] = 2;
}
void desk_set(int a, int b)
{
	map[a + 1][b] = 2;
	map[a][b] = 3;
	map[a][b + 1] = 3;
	map[a][b + 2] = 3;
	map[a][b + 3] = 3;
	map[a][b + 4] = 3;
	map[a + 1][b + 4] = 2;
	map[a + 2][b] = 3;
	map[a + 2][b + 1] = 3;
	map[a + 2][b + 2] = 3;
	map[a + 2][b + 3] = 3;
	map[a + 2][b + 4] = 3;
	for (int i = b + 1; i<b + 4; i++)
		map[a + 1][i] = 4;
}
void sleepunit(int a)
{
	Sleep(800);
	a--;
}
int teacher_senser()
{
	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<4; j++)
		{
			if (PX == TX + i&&PY == TY + i || PX == TX - i&&PY == TY - i)
				return 3;
		}
	}
	return 0;
}
void set_bundan(int a, int b)
{
	desk_set(a, b);
	desk_set(a, b + 6);
	desk_set(a + 5, b);
	desk_set(a + 5, b + 6);
	desk_set(a + 10, b);
	desk_set(a + 10, b + 6);
	desk_set(a + 15, b);
	desk_set(a + 15, b + 6);
	desk_set(a + 20, b);
	desk_set(a + 20, b + 6);
}
void prologue()
{
	printf("명수네 학교에서는 오늘 중간고사를 본다...\n\n");
	printf("문 앞의 시험지, 그리고 시험감독 선생님.\n\n");
	printf("평소의 교실의 분위기는 어디서도 찾아볼수가없다.\n\n");
	printf("그러나 전날 고급시계를한 명수는 풀수있는 문제가 거의 없었다.\n\n");
	printf("그래서 명수는 어쩔수없이 변장을하고 ");
	YELLOW;
	printf("$");
	ORIGINAL;
	printf("의 모습으로 돌아다니기로 했다!\n\n");
	_getch();
	system("cls");
	printf("그러나 교실에는 시험감독선생님이 계속 돌아다니신다.\n\n");
	printf("시험감독선생님 : 여러분! 재차 말하지만, 컨닝하지 마세요~\n\n");
	printf("시험감독 선생님 : 저는 뒤통수에도 눈이 달렸답니다~ 호호!\n\n");
	printf("선생님은 농담투로 말했지만 들리는 소문에 의하면 사실이었다.\n\n");
	printf("그 말을 한 직후 선생님은 ");
	SKY_BLUE;
	printf("&");
	ORIGINAL;
	printf("의 모습으로 돌아다니기 시작했다.\n\n");
	_getch();
	system("cls");
	printf("\"또각....또각...\"\n\n");
	printf("선생님의 발자국 소리가 시계소리처럼 규칙적으로 들려온다.\n\n");
	printf("명수를 도와 선생님에게 걸리지않고 돌아다녀보자!\n\n");
	printf("선생님의 상하좌우로 3칸이내에 있고, 그게 내자리가 아니라면 HP가 1씩 줄어든다.\n\n");
	printf("(아무키나 누르면 시작됩니다)");
	_getch();
	system("cls");
}
int leftx = 0, lefty = 0;
void check_left_distance()
{
	leftx = PX - TX;//쌤이 나의 왼쪽에 있으면 양수, 오른쪽이면 음수 
	lefty = PY - TY;//쌤이 나의 위에 있으면 양수, 아래면 음수 
}
int teacher_move_ai()
{
	Sleep(10);
	srand(time(NULL));
	int choice = rand() % 9;
	choice++;
	int str = 0;
	if (choice % 3 == 0)
	{
		if (leftx == 0)
		{
			if (lefty>0 && map[TY + 1][TX] == 0)
				TY++;
			else if (lefty<0 && map[TY - 1][TX] == 0)
				TY--;
			else
				str = 333;
		}
		else if (leftx != 0)
		{
			if (leftx>0 && map[TY][TX + 1] == 0)
			{
				TX++;
				str = 0;
			}
			else if (leftx<0 && map[TY][TX - 1] == 0)
			{
				TX--;
				str = 0;
			}
		}
		if (str == 333)
		{
			if (map[TY - 1][TX] == 0)
				TY--;
			else if (map[TY + 1][TX] == 0)
				TY++;
			else if (map[TY][TX + 1] == 0)
				TX++;
			else if (map[TY][TX - 1] == 0)
				TX--;
			else
				printf("freezing error");
		}
	}
	else
	{
		if (lefty != 0)
		{
			if (lefty>0 && map[TY + 1][TX] == 0)
				TY++;
			else if (lefty<0 && map[TY - 1][TX] == 0)
				TY--;
			else
				str = 333;
		}
		else if (lefty == 0)
		{
			if (leftx>0 && map[TY][TX + 1] == 0)
			{
				TX++;
				str = 0;
			}
			else if (leftx<0 && map[TY][TX - 1] == 0)
			{
				TX--;
				str = 0;
			}
		}
		if (str == 333)
		{
			if (map[TY][TX + 1] == 0)
				TX++;
			else if (map[TY][TX - 1] == 0)
				TX--;
			else if (map[TY + 1][TX] == 0)
				TY++;
			else if (map[TY - 1][TX] == 0)
				TY--;
			else
				printf("freezing error");
		}
	}
	Sleep(10);
	return 0;
}
void fff(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0; // bVisible 멤버 변경
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); // 변경값 적용
}
void clear_unit()
{
	system("cls");
	set();
	set_bundan(9, 7);
	set_bundan(9, 25);
	set_bundan(9, 43);
	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<width; j++)
		{
			if (map[i][j] == 0 || map[i][j] == 4)
				printf(" ");
			else if (map[i][j] == 1)
				printf("*");
			else if (map[i][j] == 2)
				printf("|");
			else if (map[i][j] == 3)
				printf("-");
			else if (map[i][j] == 5)
				printf("#");
			else
				printf("%c", map[i][j]);
		}
		printf("\n");
	}
	gotoxy(PX, PY);
	YELLOW;
	printf("$");
	ORIGINAL;
	int count = 0;
	gotoxy(TX, TY);
	SKY_BLUE;
	printf("&");
	ORIGINAL;
	gotoxy(3, height + 1);
	printf("HP : ");
	for (int i = 0; i<hp; i++)
	{
		RED;
		printf("♥ ");
		ORIGINAL;
	}
	gotoxy(28, height + 1);
	printf("score : %d", score);
}
int count_is_bigger_then_zero(int count)
{
	gotoxy(8, height + 1);
	for (int i = 0; i<hp; i++)
		printf("   ");
	hp--;
	gotoxy(8, height + 1);
	for (int i = 0; i<hp; i++)
	{
		RED;
		printf("♥ ");
		ORIGINAL;
	}
	sleepunit(count);
	count = 0;
	clear_unit();
	return 0;
}
int main()
{
	fff();
	srand(time(NULL));
	system("title 컨닝하기");
	int cycle = 1, exhp = hp, exscore = score;
	prologue();
	system("mode con cols=60 lines=40");
	set();
	set_bundan(9, 7);
	set_bundan(9, 25);
	set_bundan(9, 43);
	target();
	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<width; j++)
		{
			if (map[i][j] == 0 || map[i][j] == 4)
				printf(" ");
			else if (map[i][j] == 1)
				printf("*");
			else if (map[i][j] == 2)
				printf("|");
			else if (map[i][j] == 3)
				printf("-");
			else if (map[i][j] == 5)
				printf("#");
			else
				printf("%c", map[i][j]);
		}
		printf("\n");
	}
	gotoxy(PX, PY);
	YELLOW;
	printf("$");
	ORIGINAL;
	int count = 0;
	gotoxy(TX, TY);
	SKY_BLUE;
	printf("&");
	ORIGINAL;
	gotoxy(3, height + 1);
	printf("HP : ");
	for (int i = 0; i<hp; i++)
	{
		RED;
		printf("♥ ");
		ORIGINAL;
	}
	gotoxy(28, height + 1);
	printf("score : %d", score);
	while (1)
	{
		exhp = hp;
		exscore = score;
		if (hp == 0)
			break;
		/*if(flag==1)
		gotoxy(TX,TY-1);
		printf("&");*/
		if (_kbhit())//무빙 유닛 
		{
			exPX = PX;
			exPY = PY;
			int in = _getch();
			if (in == 'w'&&map[PY - 1][PX] == 0 && PY - 1 != 0 || in == 'w'&&map[PY - 1][PX] == 5 && PY - 1 != 0)
			{
				PY--;
				if (check_width || check_height)
				{
					gotoxy(exPX, exPY);
					printf(" ");
					count = 2;
					exPX = PX = PX_origin;
					exPY = PY = PY_origin;
				}
				if (map[PY][PX] == 5)
				{
					arrive = 1;
					score += 150;
					combo++;
				}
			}
			else if (in == 's'&&map[PY + 1][PX] == 0 && PY + 1 != height || in == 's'&&map[PY + 1][PX] == 5 && PY + 1 != height)
			{
				PY++;
				if (check_width || check_height)
				{
					gotoxy(exPX, exPY);
					printf(" ");
					count = 2;
					exPX = PX = PX_origin;
					exPY = PY = PY_origin;
				}
				if (map[PY][PX] == 5)
				{
					arrive = 1;
					score += 150;
					combo++;
				}
			}
			else if (in == 'a'&&map[PY][PX - 1] == 0 && PX - 1 != 0 || in == 'a'&&map[PY][PX - 1] == 5 && PX - 1 != 0)
			{
				PX--;
				if (check_width || check_height)
				{
					gotoxy(exPX, exPY);
					printf(" ");
					count = 2;
					exPX = PX = PX_origin;
					exPY = PY = PY_origin;
				}
				if (map[PY][PX] == 5)
				{
					arrive = 1;
					score += 150;
					combo++;
				}
			}
			else if (in == 'd'&&map[PY][PX + 1] == 0 && PX + 1 != width || in == 'd'&&map[PY][PX + 1] == 5 && PX + 1 != width)
			{
				PX++;
				if (check_width || check_height)
				{
					gotoxy(exPX, exPY);
					printf(" ");
					count = 2;
					exPX = PX = PX_origin;
					exPY = PY = PY_origin;
				}
				if (map[PY][PX] == 5)
				{
					arrive = 1;
					score += 150;
					combo++;
				}
			}
			if (arrive == 1)
			{
				if (combo % 2 == 0 && combo != 0)
					score += 270;
				map[PY][PX] = 0;
				gotoxy(PX, PY);
				printf(" ");
				PX = PX_origin;
				PY = PY_origin;
				target_family();
				arrive = 0;
				int randum = rand() % 3;
				if (randum == 1)
					hp++;
				gotoxy(TX, TY);
				printf(" ");
				exTX = TX = TX_origin;
				exTY = TY = TY_origin;
				gotoxy(TX, TY);
				SKY_BLUE;
				printf("&");
				ORIGINAL;
			}
			gotoxy(exPX, exPY);
			printf(" ");
			gotoxy(PX, PY);
			YELLOW;
			printf("$");
			ORIGINAL;
		}
		exTX = TX;
		exTY = TY;
		check_left_distance();
		if (cycle % 2300 == 0)
		{
			teacher_move_ai();
			gotoxy(exTX, exTY);
			printf(" ");
			gotoxy(TX, TY);
			SKY_BLUE;
			printf("&");
			ORIGINAL;
			Sleep(10);
		}
		cycle++;
		if (check_width || check_height)
		{
			gotoxy(PX, PY);
			printf(" ");
			Beep(7000, 100);
			gotoxy(TX, TY);
			printf(" ");
			exTX = TX = TX_origin;
			exTY = TY = TY_origin;
			count = 0;
			exPX = PX = PX_origin;
			exPY = PY = PY_origin;
			count_is_bigger_then_zero(count);
			target_family();
		}
		if (hp != exhp)
		{
			gotoxy(3, height + 1);
			printf("HP : ");
			for (int i = 0; i<hp; i++)
			{
				RED;
				printf("♥ ");
				ORIGINAL;
			}
		}
		if (score != exscore)
		{
			gotoxy(28, height + 1);
			printf("score : %d", score);
		}
	}
	system("cls");
	gotoxy(15, 10);
	GREEN;
	printf("G ");
	YELLOW;
	printf("A ");
	BLOOD;
	printf("M ");
	ORIGINAL;
	printf("E   ");
	ORIGINAL;
	printf("O ");
	BLOOD;
	printf("V ");
	YELLOW;
	printf("E ");
	GREEN;
	printf("R");
	ORIGINAL;
	printf("\n\n\n");
	printf("\t\t");
	printf("당신의 점수는 : ");
	std::cout << score << "점 입니다.";
	_getch();
}