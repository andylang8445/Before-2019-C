#include<stdio.h>
int n, color[1000];
int main()
{
	int cnt2 = 0, count1 = 0;
	for (int i = 0; i < 1000; i++)
		color[i] = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		color[tmp - 1]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (color[i] == 1)
			count1++;
		else if (color[i] > 1)
			cnt2++;
	}
	if (cnt2 >= 3 || count1 >= 6 || cnt2 != 0 && count1 != 0 && count1 + cnt2 >= 4)
		printf("YES");
	else
		printf("NO");
}