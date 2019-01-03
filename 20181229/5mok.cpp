#include<stdio.h>
int main()
{
	int n,x[10],y[10];
	int map[19][19];
	for(int i=0;i<19;i++)
		for(int j=0;j<19;j++)
			map[i][j]=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		x[i]--;
		y[i]--;
		map[x[i]][y[i]]=1;
	}
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
			printf("%d ",map[j][i]);
		printf("\n");
	}
}
