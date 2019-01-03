#include<stdio.h>
int main()
{
	int h,w;
	int n;
	int l,d,x,y;
	int map[100][100];
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			map[i][j]=0;
	scanf("%d %d",&h,&w);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&l,&d,&y,&x);
		y--;
		x--;
		for(int j=0;j<l;j++)
		{
			if(d==1)
				map[x][y+j]=1;
			else
				map[x+j][y]=1;
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			printf("%d ",map[j][i]);
		printf("\n");
	}
}
