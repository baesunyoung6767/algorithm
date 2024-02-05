#include <stdio.h>

int visited[9];
int arr[9];
int n, m;
void bt(int cnt, int idx)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = idx; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			arr[cnt] = i;
			visited[i] = 1;
			bt(cnt + 1 , i + 1);
			visited[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	bt(0,1);
}