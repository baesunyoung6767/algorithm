#include <iostream>
#define MAX 2001
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    
	int N, M;
	int arr[MAX] = { 0 };
	int dp[MAX][MAX] = { 0 };

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
		
	cin >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (i == j) dp[i][j] = 1;
			else if (i - j == 1 && arr[i] == arr[j]) dp[i][j] = 1;
			else if (dp[i - 1][j + 1] == 1 && arr[i] == arr[j] ) dp[i][j] = 1;
		}
	}

	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		cout << dp[end][start] << '\n';
	}
}