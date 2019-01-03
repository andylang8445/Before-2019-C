#include<stdio.h>
#include<conio.h>
#pragma warning(disable: 2996)
int front = 0;
int rear = 0;
int queue[105];
int arr[1005];
int arr2[1005];
int n, m;
int cnt = 0;
void push(int a);
void pop();
void top();
FILE *f;

int main()
{
	errno_t err;
	err = fopen_s(&f,"a.txt", "w");

	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d", &arr[i]);
		if (arr[i] == 1)
		{
			scanf_s("%d", &arr2[i]);
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
	_getch();
	fclose(f);
}
void push(int a)
{
	if (cnt < n)
	{
		queue[(rear++)%n] = a;
		cnt++;
	}
	else
		fprintf(f,"Overflow\n");
}
void pop()
{
	if (cnt > 0)
	{
		queue[(front++) % n] = 0;
		cnt--;
	}
	else
		fprintf(f,"Underflow\n");
}
void top()
{
	if (cnt == 0)
		fprintf(f,"NULL\n");
	else
		fprintf(f,"%d\n", queue[front%n]);
}