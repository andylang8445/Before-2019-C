#include<stdio.h>
int main()
{
	int n,x,y;
	int map[19][19];
	for(int i=0;i<19;i++)
		for(int j=0;j<19;j++)
			scanf("%d",&map[j][i]);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		x--;
		y--;
		for(int j=0;j<19;j++)
		{
			if(map[x][j]==0)
				map[x][j]=1;
			else
				map[x][j]=0;
			if(map[j][y]==0)
				map[j][y]=1;
			else
				map[j][y]=0;
		}
	}
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
			printf("%d ",map[j][i]);
		printf("\n");
	}
}
