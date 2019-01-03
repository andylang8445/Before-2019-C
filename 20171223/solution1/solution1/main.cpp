#include <stdio.h>
#include <algorithm>
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
	int min1, min2, mid;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	R = n - 1;
	L = 0;
	sort(arr, arr + n + 1);
	while (k!=n)
	{
		mid = L + R / 2;
		int sum = arr[k] + arr[n - 1];
		if (juldae(sum) < min)
		{
			min1 = arr[k];
			min2 = arr[n];
			min = juldae(sum);
		}
		if (sum < 0)
			k++;
		else if (sum > 0)
			n--;
		else
			break;
	}
	printf("%d %d", min1, min2);
}