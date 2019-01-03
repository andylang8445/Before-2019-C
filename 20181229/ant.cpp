#include<stdio.h>
int dx,dy;
int fx,fy;
int x=1,y=1;
void dis()
{
	dx=fx-x;
	dy=fy-y;
}
int main()
{
	int map[10][10];
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			scanf("%d",&map[j][i]);
			if(map[j][i]==2)
			{
				fx=j;
				fy=i;
				dis();
			}
		}
	}
	while(1)
	{
		map[x][y]=9;
		dis();
		if((dx==0&&dy==0)||(map[x][y+1]==1&&map[x+1][y]==1))
			break;
		if(map[x+1][y]!=1)
			x++;
		else if(map[x][y+1]!=1)
			y++;
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			printf("%d ",map[j][i]);
		printf("\n");
	}
}
