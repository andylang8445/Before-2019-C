#include<stdio.h>
char arr[55];
int main()
{
	int open = 0;
	fgets(arr, sizeof(arr), stdin);
	for (int i = 0; i < 50; i++)
	{
		if (arr[i] == '(')
			open++;
		else if(arr[i] == ')')
			open--;
	}
	if (open == 0)
		printf("YES");
	else
		printf("NO");
}