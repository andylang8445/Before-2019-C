#include<stdio.h>
int main()
{
	int a,r,n;
	int mul=1;
	scanf("%d %d %d",&a,&r,&n);
	n--;
	for(int i=0;i<n;i++)
		mul*=r;
	printf("%d",a*mul);
}
