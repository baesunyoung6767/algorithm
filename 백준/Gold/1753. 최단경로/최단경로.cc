#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int V, E;
int startNode = 0;
vector <pair<int, int>> graph[20010];
int result[20010] = { 0 };

void init() {
	for (int i = 1; i <= V; i++) result[i] = 987654321;
}

void checkMin() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, startNode });
	result[startNode] = 0;

	while (!q.empty()) {
		int cNode = q.top().second;
		int cPrice = q.top().first;
		q.pop();

		if (result[cNode] < cPrice) continue;

		for (int i = 0; i < graph[cNode].size(); i++) {
			int nNode = graph[cNode][i].second;
			int nPrice = graph[cNode][i].first + cPrice;

			if (result[nNode] > nPrice) {
				result[nNode] = nPrice;
				q.push({ nPrice, nNode });
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;
	cin >> startNode;

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ w,v });
	}

	init();
	checkMin();

	for (int i = 1; i <= V; i++) {
		if (result[i] == 987654321) cout << "INF\n";
		else cout << result[i] << "\n";
	}
}