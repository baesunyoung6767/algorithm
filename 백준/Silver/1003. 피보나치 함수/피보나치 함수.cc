#include <stdio.h>

void fibo(int n)
{
	int last, cur, result;
	cur = 1, last = result = 0;
	
	for (int i = 0; i <= n; i++)
	{
		last = cur;
		cur = result;
		result = last + cur;
	}
	printf("%d %d\n", last, cur);
}

int main()
{
	int n, m;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		fibo(m);
	}
}