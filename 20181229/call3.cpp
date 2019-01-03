#include<stdio.h>
int main()
{
	int n,tmp,min=23;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		if(tmp<min)
			min=tmp;
	}
	printf("%d",min);
}
