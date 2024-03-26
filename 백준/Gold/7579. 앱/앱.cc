#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int N, M;
int app[MAX] = { 0 };
int cost[MAX] = { 0 };
int costSum = 0;
int dp[MAX][10001] = { 0 };

int main() {
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) cin >> app[i];
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		costSum += cost[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= costSum; j++) {
			if (cost[i] > j) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + app[i]);
			}
		}
	}

	for (int i = 0; i <= costSum; i++) {
		if (dp[N][i] >= M) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}