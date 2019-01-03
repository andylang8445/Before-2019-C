#include<stdio.h>
//#include<conio.h>
int n;
typedef struct asdf {
	int h;
	int r = 0;
}tower;
tower a[500004];
int main()
{
	scanf/*_s*/("%d", &n);
	for (int i = 0; i < n; i++)
		scanf/*_s*/("%d", &a[i].h);
	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j].h > a[i].h)
			{
				a[i].r = j + 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i].r);
	//_getch();
}