#include<stdio.h>
int main()
{
	int h,b,c,s;
	double result;
	scanf("%d %d %d %d",&h,&b,&c,&s);
	result=(h*b*c*s);
	result/=8;
	result/=1024;
	result/=1024;
	printf("%.1f MB\n",result);
}
