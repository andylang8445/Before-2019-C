#include<stdio.h>
int n, arr[85];
bool k = true;
int chk(int current)
{
	for (int i = 1; i <= current / 2; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= i; j++)
		{
			if (arr[current - j] == arr[current - j - i])
				cnt++;
		}
		if (cnt == i)
			return 1;
	}
	return 0;
}
int f(int a)
{
	if (!k)
		return 0;
	if (chk(a))
		return 0;
	if (a == n)
	{
		if (k)
		{
			for (int i = 0; i < n; i++)
				printf("%d", arr[i]);
			k = false;
		}
		return 0;
	}
	arr[a] = 1;
	f(a + 1);
	arr[a] = 2;
	f(a + 1);
	arr[a] = 3;
	f(a + 1);
}
int main()
{
	scanf("%d", &n);
	f(0);
}