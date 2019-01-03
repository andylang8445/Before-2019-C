#include<stdio.h>
int main()
{
	int n,arr[26];
	for(int i=0;i<23;i++)
		arr[i]=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		arr[arr[25]-1]++;
	}
	for(int i=0;i<23;i++)
		printf("%d ",arr[i]);
}
