#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int N, M;
vector<pair<int, int>> v[MAX];
int startNode, endNode;
int cost[MAX] = { 0 };

void check(int node) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, node });
	cost[node] = 0;

	while (!pq.empty()) {
		int ccost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost[cur] < ccost) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second + ccost;

			if (cost[next] > ncost) {
				cost[next] = ncost;
				pq.push({ ncost, next });
			}
		}
	}
}

int main() {
	cin >> N >> M;
	
	int to, from, price;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> price;
		v[from].push_back({ to, price });
	}

	for (int i = 1; i <= N; i++) cost[i] = 987654321;

	cin >> startNode >> endNode;	
	check(startNode);
	cout << cost[endNode] << '\n';

}