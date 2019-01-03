#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int N, r; int p_cnt, q_cnt, p, q;
int flag_p, flag_q, flag;
int p_chk[32]; char p_pnt[32];
char p_prt[32], q_prt[32];

int nPr(int n)
{
	int i;

	if (n == N) {
		/* nPr */
		++p_cnt;
		if (p_cnt == p) {
			strcpy(p_prt, p_pnt);
			flag_p = 1;
		}
		/* nCr */
		if (flag_p == 1 && flag_q == 1) {
			printf("%s\n%s", p_prt, q_prt);
			exit(0);
		}
		flag = 0;
		for (i = 0; i<N - 1; i++) {
			if (p_pnt[i]>p_pnt[i + 1]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) ++q_cnt;
		if (q_cnt == q && flag == 0) {
			strcpy(q_prt, p_pnt);
			flag_q = 1;
		}
		return 0;
	}

	for (i = 0; i<r; i++) {
		if (p_chk[i] == 0) {
			p_chk[i] = 1; p_pnt[n] = i + 'A';
			nPr(n + 1);
			p_chk[i] = 0; p_pnt[n] = i + 'A';
		}
	}
}
int main(void)
{
	scanf("%d%d", &r, &N);
	scanf("%d%d", &p, &q);

	nPr(0);

	return 0;
}