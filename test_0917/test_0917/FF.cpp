#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j < n; j++)
			printf(" ");
		if (i != (n + 1) / 2)
		{
			printf("*");
			for (int j = 0; j < i * 2 - 3; j++)
			{
				printf(" ");
			}
			if (i != 1)
				printf("*");
		}
		else
		{
			for (int j = 0; j < n; j++)
				printf("*");
		}
		printf("\n");
	}
}