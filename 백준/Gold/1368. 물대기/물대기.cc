#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 301
using namespace std;

int N;
//int water[MAX][MAX] = { 0 };
//bool inWater[MAX];
int parent[MAX] = { 0 };

int result = 0;

vector<pair<int, pair<int, int>>> water;

bool cmp(pair<int, pair<int, int>>a, pair<int, pair<int, int>> b) {
	return a.first < b.first;
}

int find(int node) {
	if (parent[node] == node) return node;
	else return parent[node] = find(parent[node]);
}


void check() {
	
	for (int i = 0; i < water.size(); i++) {
		int cost = water[i].first;
		int from = water[i].second.first;
		int to = water[i].second.second;

		int fromP = find(from);
		int toP = find(to);

		if (fromP != toP) {
			if (fromP < toP) parent[toP] = fromP;
			else parent[fromP] = toP;
			result += cost;
		}
	}

}

int main() {
	cin >> N;

	int minCost = 987654321;
	int minIdx = -1;

	int temp;
	// i번째 우물을 팔 때 드는 비용
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		water.push_back({ temp, {0, i} });
		parent[i] = i;
	}

	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			water.push_back({ temp, {i, j} });
		}
	}

	sort(water.begin(), water.end(), cmp);
	check();
	cout << result << '\n';
	
}