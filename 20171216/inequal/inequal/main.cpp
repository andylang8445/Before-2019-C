#include<stdio.h>
int num[10], chk[10], n, first[10], last[10], x;
int tmpp = 0;
char arr[10];
int f(int b)
{
	if (b == n + 1)
	{
		if (tmpp == 0)
		{
			for (int i = 0; i <= n; i++)
				first[i] = num[i];
			tmpp = 1;
		}
		for (int i = 0; i <= n; i++)
			last[i] = num[i];
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		if (chk[i] == 0)
		{
			if (b > 0)
			{
				if (arr[b-1] == '<')
				{
					if (num[b - 1] < i)
					{
						chk[i] = 1;
						num[b] = i;
						f(b + 1);
						chk[i] = 0;
					}
				}
				else if (arr[b-1] == '>')
				{
					if (num[b - 1]>i)
					{
						chk[i] = 1;
						num[b] = i;
						f(b + 1);
						chk[i] = 0;
					}
				}
			}
			else {
				chk[i] = 1;
				num[b] = i;
				f(b + 1);
				chk[i] = 0;
			}
		}
	}
}
int main()
{
	scanf("%d ", &n);
	for (int i = 0; i < n; i++)
		scanf(" %c", &arr[i]);
	f(0);
	for (int i = 0; i <= n; i++)
		printf("%d", last[i]);
	printf("\n");
	for (int i = 0; i <= n; i++)
		printf("%d", first[i]);
}