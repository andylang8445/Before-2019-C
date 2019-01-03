#include<stdio.h>
//#include<conio.h>
//#pragma warning(disable: 4996)
char stack[55], in[55];
int top = -1;
int main()
{
	scanf("%s", in);
	for (int i = 0; in[i] != NULL; i++)
	{
		if (in[i] == '(')
			stack[top++] = '(';
		else if (in[i] == ')'&&top > -1)
			top--;
	}
	if (top == -1)
		printf("YES");
	else
		printf("NO");
	//_getch();
}