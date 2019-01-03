#include<stdio.h>
int a[1000000];
#define giant(a,b)   (((a) > (b)) ? (a) : (b))

int main()
{
	int n, m, b = 0, L = 0, R = 0;
	long long int mid, sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++)
	{
		scanf("%d", a + i);
		R = b = giant(b, a[i]);
	}
	while (L < R)
	{
		mid = (L + R + 1) / 2;
		sum = 0;
		for (int i = 0; i<n; i++)
			sum += giant(0, a[i] - mid);
		if (sum < m)
			R = mid - 1;
		else
			L = mid;
	}
	printf("%d", L);
}