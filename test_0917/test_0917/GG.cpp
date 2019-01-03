#include<stdio.h>
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++)
		printf("*");
	printf("\n");
	for (int i = 0; i < b - 2; i++)
	{
		printf("*");
		for (int j = 0; j < a - 2; j++)
			printf(" ");
		printf("*");
		printf("\n");
	}
	for (int i = 0; i < a; i++)
		printf("*");
	return 0;
}