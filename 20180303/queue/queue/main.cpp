#include<stdio.h>
//#include<conio.h>
int front = 0;
int rear = 0;
int queue[105];
int arr[1005];
int arr2[1005];
int n, m;
void push(int a);
void pop();
void top();
int main()
{
	scanf/*_s*/("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf/*_s*/("%d", &arr[i]);
		if (arr[i] == 1)
		{
			scanf/*_s*/("%d", &arr2[i]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (arr[i] == 1)
			push(arr2[i]);
		else if (arr[i] == 2)
			pop();
		else
			top();
	}
	//_getch();
}
void push(int a)
{
	if (rear < n)
		queue[rear++] = a;
	else
		printf("Overflow\n");
}
void pop()
{
	if (front < rear)
		front++;
	else
		printf("Underflow\n");
}
void top()
{
	if (front < rear)
		printf("%d\n", queue[front]);
	else
		printf("NULL\n");
}