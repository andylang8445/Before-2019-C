#include<stdio.h>
#include<conio.h>
int list[100005];
int main()
{
	int a, k, max = 0;
	int open = 0;
	scanf_s("%d", &a);
	for (int i = 1; i <= a * 2; i++)
	{
		scanf_s("%d", &k);
		if (list[k] == 0)
		{
			list[k] = 1;
			open++;
		}
		else
		{
			list[k] = 0;
			open--;
		}
		if (open > max)
			max = open;
	}
	printf("%d", max);
	_getch();
}