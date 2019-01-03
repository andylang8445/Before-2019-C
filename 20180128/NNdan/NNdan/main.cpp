#include<stdio.h>
/*#include<conio.h>
#include<math.h>
#include<Windows.h>*/
int n;
int k;
int main()
{
	int mid, l, r;
	int cnt = 0;
	int exmid = 0;
	scanf/*_s*/("%d", &n);
	scanf/*_s*/("%d", &k);
	l = 1;
	r = n*n;
	while (1)
	{
		mid = (l + r) / 2;

		//Beep(500, 200);
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (mid > i*n)
				cnt += n;
			else if (mid < i*n)
				cnt += mid / i;
			else
				cnt += n - 1;
		}
		//printf("L:%d mid:%d R:%d cnt:%d\n", l, mid, r, cnt);
		if (cnt > k - 1)
			r = mid;
		else if (cnt < k - 1)
			l = mid;
		else
			break;
		if (l == r || exmid == mid)
			break;
		exmid = mid;
		cnt = 0;
	}
	printf("%d", mid + 1);
	//_getch();
}