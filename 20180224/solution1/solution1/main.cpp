#include <stdio.h>
#include <algorithm>
//#include <conio.h>
using namespace std;
int juldae(int a)
{
	if (a < 0)
		a *= -1;
	return a;
}

int arr[100005];
int main()
{
	int l, r;
	int mid;
	int min=9999999;
	int save_a, save_b;
	int n;
	scanf/*_s*/("%d", &n);
	for (int i = 0; i < n; i++)
		scanf/*_s*/("%d", &arr[i]);
	//sort
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++)
	{
		r = n - 1;
		l = i + 1;
		//ÀÌÁøÅ½»ö
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (min > juldae(arr[i] + arr[mid]))
			{
				min = juldae(arr[i] + arr[mid]);
				save_a = arr[i];
				save_b = arr[mid];
			}
			if (arr[i] + arr[mid] < 0)
				l = mid + 1;
			else if (arr[i] + arr[mid] > 0)
				r = mid - 1;
			else
				break;
		}
	}
	printf("%d %d", save_a, save_b);
	//_getch();
}