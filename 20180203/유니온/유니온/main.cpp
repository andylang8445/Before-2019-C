#include<stdio.h>
#include<conio.h>
long long int arr[2][10005];
int main()
{
	long long int k;
	long long int current_open = 0;
	long long int n;
	long long int r, l, mid;
	long long int exr, exl;
 	long long int lower, ex;
	scanf_s("%lld", &n);
 	for (int i = 1; i <= n; i++)
		scanf_s("%lld %lld", &arr[0][i], &arr[1][i]);
	scanf_s("%lld", &k);
	l = 1;
	r = n;
	while (1)
	{
		mid = (l + r) / 2;
		lower = 0;
		ex = lower;
		exl = l;
		exr = r;
		printf("L:%lld R:%lld mid:%lld lower: %lld ex:%lld\n", l, r, mid, lower, ex);
		for (int i = 1; i <= n; i++)
			lower += mid - arr[0][i];
		if (lower > k)
			r = mid;
		if (lower < k)
			l = mid;
		printf("L:%lld R:%lld mid:%lld lower: %lld ex:%lld\n", l, r, mid, lower, ex);
		if (lower == k||ex == lower || l >= r || exl == l && exr == r)
			break;
	}
	printf("%lld", mid);
	_getch();
}