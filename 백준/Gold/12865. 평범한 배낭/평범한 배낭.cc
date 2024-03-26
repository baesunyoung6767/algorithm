#include <iostream>
#include <algorithm>
#define KMAX 100001
#define NMAX 101
using namespace std;

int main() {
	int N, K;
	int weight[NMAX];
	int value[NMAX];
	int dp[NMAX][KMAX] = { 0, };
	cin >> N >> K;

	for (int i = 1; i <= N; i++) cin >> weight[i] >> value[i];

	for (int limit = 1; limit <= K; limit++) {
		for (int cnt = 1; cnt <= N; cnt++) {
			if (weight[cnt] > limit)
				dp[cnt][limit] = dp[cnt-1][limit];
			else 
				dp[cnt][limit] = max(dp[cnt - 1][limit - weight[cnt]] + value[cnt], dp[cnt - 1][limit]);
		}
	}

	cout << dp[N][K] << '\n';
	
	return 0;
}

