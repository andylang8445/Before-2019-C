#include <stdio.h>
int a;
int  main()
{
	int arr[50][50];
	int p, b;
	int t = 1, nef = 1, y = -1, x = 0;
	scanf("%d", &p);
	b = a = p;
	while (0 <= b)
	{
		for (int i = 0; i < b; i++)
		{
			y = y + t;
			arr[x][y] = nef;
			nef++;
		}
		b--;
		for (int i = 0; i < b; i++)// ¿­ Ç¥Çö
		{
			x = x + t;
			arr[x][y] = nef;
			nef++;
		}
		t *= -1;
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return 0;
}