#include<stdio.h>
//#include<conio.h>
//#pragma warning(disable: 4996)
int multiple = 1;
int sum = 0;
int n, m;
char queue[50];
int main()
{
	scanf("%s", queue);
	for (int i = 0; queue[i] != NULL; i++)
	{
		if (queue[i] == '(')
		{
			n++;
			multiple *= 2;
			if (queue[i + 1] != NULL && queue[i + 1] == ')')
				sum += multiple;
		}
		else if (queue[i] == '[')
		{
			m++;
			multiple *= 3;
			if (queue[i + 1] != NULL && queue[i + 1] == ']')
				sum += multiple;
		}
		else if (queue[i] == ')')
		{
			n--;
			multiple /= 2;
		}
		else if (queue[i] == ']')
		{
			m--;
			multiple /= 3;
		}
	}
	if (n != 0 || m != 0)
		printf("0");
	else
		printf("%d", sum);
	//_getch();
}