#include<stdio.h>
#include <algorithm>
using namespace std;
int arr[100005];
int cnt = 0;
int in[100005];
int question[100005];

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	sort(arr, arr + n + 1);
	for (int i = 0; i < n; i++)
		arr[in[i]]++;
	for (int i = 0; i < q; i++)
		scanf("%d", &question[i]);
	for (int i = 0; i < q; i++)
		question[i] = arr[question[i]];
	for (int i = 0; i < q; i++)
		printf("%d\n", question[i]);
}