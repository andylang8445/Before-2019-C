#include<stdio.h>
#define n 10
int original[n] = { 2,0,8,6,4,5,10,3,1,7 };
int f(int* arr, int a)
{
	if (a < 2)
		return 0;
	int mid = a / 2;
	f(arr, mid);
	f(arr + mid, a - mid);


}
int main()
{
	f(original,n);
}