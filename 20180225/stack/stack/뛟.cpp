#include <stdio.h>
#include<conio.h>

int MAXSIZE;
int stack[105];
int cnt = 0;
int arr[1005];
int arr2[1005];
int top = -1;

int push(int val) {
	if (top >= MAXSIZE - 1) {
		printf("Overflow\n");
		return -1;
	}
	stack[++top] = val;
	return val;
}
int pop(void) {
	if (top < 0) {
		printf("Underflow\n");
		return -1;
	}
	return stack[top--];
}
void Top()
{
	if (top >= 0)
		printf("%d\n", stack[top]);
	else
		printf("NULL\n");
}
void main(void)
{
	int re;
	scanf_s("%d %d", &MAXSIZE, &cnt);
	for (int i = 0; i < cnt; i++)
	{
		scanf_s("%d", &arr[i]);
		if(arr[i]==1)
			scanf_s("%d", &arr2[i]);
	}
	for (int i = 0; i < cnt; i++)
	{
		if (arr[i] == 1)
			re = push(arr2[i]);
		else if (arr[i] == 2)
			re = pop();
		else
			Top();
	}
	_getch();
}