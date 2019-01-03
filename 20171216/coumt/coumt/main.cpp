#include<stdio.h>
int n, q;
int num[100000], question[100000];
void sort()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (num[i] > num[j])
			{
				int tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}
}
int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	for (int i = 0; i < q; i++)
		scanf("%d", &question[i]);
	sort();

}