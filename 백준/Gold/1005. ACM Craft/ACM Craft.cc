#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

int main() {
	int T; cin >> T;

	while (T--) {
		int N, K, W ; // 건물 개수, 건설 규칙 순서 개수
		int cost[MAX] = { 0 };
		int isBefore[MAX] = { 0 };
		int dp[MAX] = { 0 };

		vector<int> v[MAX];
		queue<int> q;

		cin >> N >> K;
		
		for (int i = 1; i <= N; i++) cin >> cost[i];

		int a, b;
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			isBefore[b]++;
		}

		cin >> W;

		for (int i = 1; i <= N; i++) {
			if (isBefore[i] == 0) {
				dp[i] = cost[i];
				q.push(i);
			}
		}

		while (N--) {
			if (q.empty()) break;

			int node = q.front();
			q.pop();

			for (int i = 0; i < v[node].size(); i++) {
				int next = v[node][i];
				isBefore[next]--;
				dp[next] = max(dp[next], dp[node] + cost[next]);
				if (isBefore[next] == 0) q.push(next);
			}
		}

		cout << dp[W] << '\n';
	}
}