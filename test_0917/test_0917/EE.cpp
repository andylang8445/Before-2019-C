#include<stdio.h>
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	for (int i = a; i < b; i++)
		printf("%d ", i);
	for (int i = b; i >= c; i--)
		printf("%d ", i);
	return 0;
}