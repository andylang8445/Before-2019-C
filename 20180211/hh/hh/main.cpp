#include<stdio.h>
#include<conio.h>
int n, color[1005];
int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		color[k]++;
	}
}