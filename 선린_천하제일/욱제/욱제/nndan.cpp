#include<stdio.h>
#include<algorithm>
int n;
int k;
int main()
{
	int mid, l, r;
	int exmid;
	scanf_s("%d", &n);
	scanf_s("%d", &k);
	l = 1;
	r = n*n;
	while (1)
	{
		mid = (l + r) / 2;
		if (exmid == mid)
			break;
		exmid = mid;
	}
}