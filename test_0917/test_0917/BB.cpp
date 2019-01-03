#include<stdio.h>
int main()
{
	int tmp, sum = 0;
	scanf("%d", &sum);
	scanf("%d", &tmp);
	sum += tmp;
	scanf("%d", &tmp);
	sum -= tmp;
	printf("%d", sum);
	return 0;
}