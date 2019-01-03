#include<stdio.h>
int main()
{
	int a,m,d,n;
	scanf("%d %d %d %d",&a,&m,&d,&n);
	n--;
	for(int i=0;i<n;i++)
	{
		a*=m;
		a+=d;
	}
	printf("%d",a);
}
