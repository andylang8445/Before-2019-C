#include<stdio.h>
#include<conio.h>
int num[10], chk[10], n, max = 0, min = 99999999, x;
char arr[10];
int f(int b)
{
	if (b == n + 1)
	{
		for (int i = 0; i <= n; i++)
			printf("%d ", num[i]);
		printf("\n");
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		if (chk[i] == 0)
		{
			if (b > 1)
			{
				if (arr[b] == '>')
				{
					if (i < num[b - 1]);
					else
						continue;
				}
				else if (arr[b] == '<')
				{
					if (i > num[b - 1]);
					else
						continue;
				}
			}
			chk[i] = 1;
			num[b] = i;
			f(b + 1);
			chk[i] = 0;
		}
	}
}
int main()
{
	scanf_s("%d ", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%c", &arr[i]);
		f(0);
		_getch();
}