#include<stdio.h>
//#include<conio.h>
int n, r;
bool chk[30];
char arr[30];
int f(int a)
{
	if (a == r)
	{
		for (int i = 0; i < r; i++)
			printf("%c", arr[i]);
		printf("\n");
		return 0;
	}
	for (int j = 0; j < n; j++)
	{
		if (chk[j] == false)
		{
			chk[j] = true;
			arr[a] = 'a' + j;
			f(a + 1);
			chk[j] = false;
		}
	}
}
int main()
{
	for (int i = 0; i < 30; i++)
		chk[i] = false;
	scanf/*_s*/("%d %d", &n, &r);
	f(0);
	//_getch();
}