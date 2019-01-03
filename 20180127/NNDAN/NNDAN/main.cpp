#include<stdio.h>
#include<algorithm>
int n;
int k;
int main()
{
	int mid1, l1, r1;
	int mid2, l2, r2;
	int exmid1, exmid2;
	scanf_s("%d", &n);
	scanf_s("%d", &k);
	l1 = l2 = 1;
	r1 = r2 = n;
	while (1)
	{
		mid1 = (l1 + r1) / 2;
		mid2 = (l2 + r2) / 2;
		if (exmid1 == mid1&&exmid2 == mid2)
			break;
		exmid1 = mid1;
		exmid2 = mid2;
	}
}