#include<stdio.h>
int main()
{
	int arr[4];
	for (int i = 0; i < 4; i++)
		scanf("%d", &arr[i]);
	printf("%d %d %d %d", arr[3], arr[2], arr[0], arr[1]);
	return 0;
}