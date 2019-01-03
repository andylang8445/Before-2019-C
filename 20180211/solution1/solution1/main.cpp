#include <stdio.h>
#include <algorithm>
#include <conio.h>
using namespace std;

int arr[100005];
int main()
{
	int k = 0, L, R;
	int Jul;
	int n, min;
	int min1, min2, mid;
	scanf_s("%d", &n);
	min = min1 = min2 = 999999999;
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	R = n - 1;
	L = 0;
	sort(arr, arr + n);
	printf("arr: ");
	for (int i = 0; i < n; i++)
	printf("%d ", arr[i]);
	printf("\n");
	while (k != n)
	{
		mid = k + n - 1 / 2;
		int sum = arr[k] + arr[n - 1];
		printf("L:%d,R:%d sum:%d mid:%d min:%d\n", k, n, sum, mid, min);
		if (sum < 0)
			Jul = -sum;
		else
			Jul = sum;
		if (Jul <= min)
		{
			if (min1 > arr[k] || min1 > arr[n - 1])
			{
				if (arr[k] < arr[n - 1])
				{
					min1 = arr[k];
					min2 = arr[n - 1];
				}
				else
				{
					min2 = arr[k];
					min1 = arr[n - 1];
				}
				min = Jul;
			}
			printf("\tmin1:%d min2:%d min:%d\n", min1, min2, min);
		}
		if (sum < 0)
			k++;
		else if (sum > 0)
			n--;
		else
			break;
	}
	printf("%d %d", min1, min2);
	_getch();
}