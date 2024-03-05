#include <stdio.h>
#include <math.h>
#define MAX 14

int chess[MAX] = { 0 };
int N, count = 0;

void DFS(int x)
{
	for (int i = 0; i < x; i++)
	{
		if ((abs(chess[x] - chess[i]) == abs(i - x)) || chess[i] == chess[x]) return;
	}
	if (x == N - 1)
	{
		count++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		chess[x + 1] = i;
		DFS(x + 1);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		chess[0] = i;
		DFS(0);
	}
	printf("%d\n", count);
}