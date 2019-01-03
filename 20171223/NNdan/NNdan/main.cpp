#include<stdio.h>
int n;
long long int k;
int *arr;
int main()
{
	void *malloc(size_t size);
	scanf("%d %lld", &n, &k);
	arr = (int*)malloc(sizeof(int)*n*n);
}