#include<stdio.h>
int main()
{
	int a,b,c;
	int max;
	scanf("%d %d %d",&a,&b,&c);
	max=a;
	if(max<b)
		max=b;
	if(max<c)
		max=c;
	for(int i=max;;i++)
	{
		if(i%a==0&&i%b==0&&i%c==0)
		{
			printf("%d",i);
			return 0;
		}
	}
}
