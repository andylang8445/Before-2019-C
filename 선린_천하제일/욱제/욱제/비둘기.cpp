#include<stdio.h>
#include<conio.h>
int main()
{
	int n, m, arr[503][503];
	int max = 0, cnt;
	int allcnt = 0;
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &arr[i][j]);
			if (arr[i][j] == 9)
				allcnt++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 9)
				cnt++;
		if (max < cnt)
			max = cnt;
		cnt = 0;
		for (int j = 0; j < m; j++)
			if (arr[j][i] == 9)
				cnt++;
		if (max < cnt)
			max = cnt;
	}
	printf("%d", allcnt - max);
	_getch();
}