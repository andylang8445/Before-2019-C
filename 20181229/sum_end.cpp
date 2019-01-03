#include<stdio.h>
int main()
{
	int n;
	int sum=0;
	scanf("%d",&n);
	for(int i=0;i<14143;i++)
	{
		if(n<=(i*(i+1)/2))
		{
			printf("%d",i*(i+1)/2);
			return 0;
		}
	}
}
