#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
long long bridge[1000001];
long long dp[1000001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) cin >> bridge[i];

	for (int i = 2; i <= N; i++) {
		dp[i] = 987654321;
		for (int j = 1; j < i; j++) {
			dp[i] = min(dp[i], max(dp[j], (i - j) * (1 + abs(bridge[i] - bridge[j]))));
		}
	}
	cout << dp[N] << '\n';
}