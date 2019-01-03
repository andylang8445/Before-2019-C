#include<stdio.h>
#define MAXN  100000
int a[MAXN], b[MAXN], an, bn;
int Op, Opa, Opb, Di;
#define Swap(aa, bb){int cc = aa;aa = bb;bb = cc;}
void Sort_a(int L, int R)
{
	if (L < R)
	{
		int i = L - 1, j = R + 1, mid = a[(L + R) >> 1];
		while (1)
		{
			while (a[++i] < mid);
			while (a[--j] > mid);
			if (i >= j) break;
			Swap(a[i], a[j]);
		}
		Sort_a(L, i - 1);
		Sort_a(j + 1, R);
	}
}
void Sort_b(int L, int R)
{
	if (L < R)
	{
		int i = L - 1, j = R + 1, mid = b[(L + R) >> 1];
		while (1)
		{
			while (b[++i] < mid);
			while (b[--j] > mid);
			if (i >= j) break;
			Swap(b[i], b[j]);
		}
		Sort_b(L, i - 1);
		Sort_b(j + 1, R);
	}
}
int main(void)
{
	int L1, L2, L3, T1, n;
	scanf("%d", &n);
	for (L1 = 0; L1 < n; L1++)
	{
		scanf("%d", &T1);
		if (T1 > 0)
			a[an++] = T1;
		else
			b[bn++] = T1;
	}
	Sort_a(0, an - 1);
	Sort_b(0, bn - 1);
	Op = 2147483647;
	if (an > 1)
	{
		Di = a[0] + a[1];
		if (Di < Op)
		{
			Op = Di;
			Opa = a[0];
			Opb = a[1];
		}
	}
	if (bn > 1)
	{
		Di = -b[bn - 1] - b[bn - 2];
		if (Di < Op)
		{
			Op = Di;
			Opa = b[bn - 2];
			Opb = b[bn - 1];
		}
	}
	if (an > 0 && bn > 0)
	{
		L2 = bn - 1;
		for (L1 = 0; L1<an; L1++)
		{
			while (L2 >= 0 || a[L1] + b[L2] > 0)
				L2--;
			for (L3 = L2 - 1; L3 <= L2 + 1; L3++)
			{
				if (L3 < 0 || L3 >= bn)
					continue;

				Di = a[L1] + b[L3];
				if (Di < 0)
					Di = Di*(-1);
				if (Di < Op)
				{
					Op = Di;
					Opa = b[L3];
					Opb = a[L1];
				}
			}
		}
	}
	printf("%d %d\n", Opa, Opb);
}