#include<stdio.h>
int main()
{
	int w,h,b;
	double result;
	scanf("%d %d %d",&w,&h,&b);
	result=(w*h*b);
	result/=1024;
	result/=8;
	result/=1024;
	printf("%.2f MB\n",result);
}
