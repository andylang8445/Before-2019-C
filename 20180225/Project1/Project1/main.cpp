#include<stdio.h>
//#include<conio.h>
int color[300005];
int n, m;
int maxx = 0;
int l = 0, r;
int n2;
int mid;

int main()
{
	scanf/*_s*/("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf/*_s*/("%d", &color[i]);
		if (maxx < color[i])
			maxx = color[i];
	}
	r = maxx;
	while (l < r)
	{
		mid = (l + r) / 2;
		n2 = 0;
		for (int i = 0; i < m; i++)
			n2 += (color[i] + mid - 1) / mid;
		if (n2 > n)
			l = mid + 1;
		else
			r = mid;
	}
	printf("%d", l);
	//_getch();
}