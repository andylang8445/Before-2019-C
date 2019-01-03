#include<stdio.h>
#include<conio.h>
int arr[2][10005];
int main()
{
	long long int k;
	int current_open = 0;
	int max = 0, min = 1000000000;
	int tmp;
	int n;
	long long int cnt = 0, excnt = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d", &arr[0][i], &arr[1][i]);
		if (arr[0][i] < min)
			min = arr[0][i];
		if (arr[1][i] > max)
			max = arr[1][i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[0][i] > arr[0][j])
			{
				tmp = arr[0][i];
				arr[0][i] = arr[0][j];
				arr[0][j] = tmp;
				tmp = arr[1][i];
				arr[1][i] = arr[1][j];
				arr[1][j] = tmp;
			}
		}
	}
	scanf_s("%lld", &k);
	for (int i = min; i <= max; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[1][j] == i)
				current_open--;
			if (arr[0][j] == i)
				current_open++;
		}
		excnt = cnt;
		cnt += current_open;
		if (excnt < k&&cnt >= k)
		{
			printf("%d", i);
			break;
		}
	}
	_getch();
}