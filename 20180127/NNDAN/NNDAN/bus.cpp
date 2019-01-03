#include<stdio.h>
#include<conio.h>
int main()
{
	int a, arr[200005], max = 0;
	int cnt = 0;
	int excnt;
	int open = 0;
	scanf_s("%d", &a);
	for (int i = 1; i <= a * 2; i++)
	{
		scanf_s("%d", &arr[i]);
		excnt = cnt;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				cnt++;
				open--;
			}
		}
		if (excnt == cnt)
			open++;
		if (open > max)
			max = open;
	}
	printf("%d", max);
	_getch();
}