#include <stdio.h>
#include<algorithm>
//#include<conio.h>
using namespace std;

int arr[100005];
int juldae(int a)
{
	if (a >= 0)
		return a;
	else
		return 0;
}
int main()
{
	int k = 0, L, R;
	int n, min = 999999999;
	int min1, min2, mid, sum;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	R = n - 1;
	L = 0;
	if (n == 2)
	{
		min1 = arr[0];
		min2 = arr[1];
		if (min1 < min2)
			printf("%d %d", min1, min2);
		else
			printf("%d %d", min2, min1);
		return 0;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++)
	{
		while (1)
		{

		}
	}
	if (min1 < min2)
		printf("%d %d", min1, min2);
	else
		printf("%d %d", min2, min1);
}