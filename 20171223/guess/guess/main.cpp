#include<stdio.h>
//#include<conio.h>
long long int a, mid, ex;
long long int L = 0, R = 10000000000;
int main()
{
	scanf/*_s*/("%lld", &a);
	while (L < R)
	{
		ex = mid;
		mid = (L + R) / 2;
		//printf("f(%lld) = %lld, %lld\n",mid, mid*(mid + 1), a);
		if (a == mid*(mid + 1) || ex == mid)
			break; 
		else if (a < mid*(mid + 1))
			R = mid;
		else if (a > mid*(mid + 1))
			L = mid;
		
	}
	//printf("%lld %lld\n", mid*(mid + 1), a);
	printf("%lld", mid);
	//_getch();
}