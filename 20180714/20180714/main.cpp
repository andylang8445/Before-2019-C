#include<stdio.h>
const int MAX = 100;
struct Tree {
	int left;
	int right;
};
Tree tree[MAX];
void pre(int x)
{
	if (tree[x].left == -1 && tree[x].right == -1)
		printf("%d ", x);
	else
	{
		printf("%d ", x);
		if (tree[x].left != -1)
			pre(tree[x].left);
		if (tree[x].right != -1)
			pre(tree[x].right);
	}
}
void in(int x)
{
	if (tree[x].left == -1 && tree[x].right == -1)
		printf("%d ", x);
	else
	{
		if (tree[x].left != -1)
			pre(tree[x].left);
		printf("%d ", x);
		if (tree[x].right != -1)
			pre(tree[x].right);
	}
}
void post(int x)
{
	if (tree[x].left == -1 && tree[x].right == -1)
		printf("%d ", x);
	else
	{
		if (tree[x].left != -1)
			pre(tree[x].left);
		if (tree[x].right != -1)
			pre(tree[x].right);
		printf("%d ", x);
	}
}
int main()
{
	int n;
	scanf/*_s*/("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf/*_s*/("%d %d %d", &a, &b, &c);
		tree[a].left = b;
		tree[a].right = c;
	}
	/*for (int i = 1; i <= n; i++)
		printf("%d:%d %d\n", i, tree[i].left, tree[i].right);*/
	pre(0);
	in(0);
	post(0);
	return 0;
}