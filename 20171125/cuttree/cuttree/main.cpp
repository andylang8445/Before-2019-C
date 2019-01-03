#include<stdio.h>
int n, m, sum = 0, h = 0;
int tree[1000000];
int main()
{
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &tree[i]);
	while (1)
	{
		h++;
		for (int i = 0; i < n; i++)
		{
			sum += tree[i] - h;
		}
		if (sum < m)
			break;
		sum = 0;
	}
	printf("%d", h);
}