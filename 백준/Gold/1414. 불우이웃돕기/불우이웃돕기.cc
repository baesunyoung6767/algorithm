#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51
using namespace std;

int N;
int map[MAX][MAX] = { 0 };
vector<pair<int, pair<int, int>>> v;
int parent[MAX] = { 0 };
//int result = 0;
//int selected[MAX] = { 0 };
int total = 0;

int find(int node) {
	if (parent[node] == node) return node;
	else return parent[node] = find(parent[node]);
}

void connect() {
	for (int i = 0; i < v.size(); i++) {
		int a = v[i].second.first;
		int b = v[i].second.second;
		int cost = v[i].first;

		int pa = find(a);
		int pb = find(b);

		if (pa != pb) {
			if (pa < pb) parent[pb] = pa;
			else parent[pa] = pb;
			total -= cost;
		}
	}
}

int main() {
	cin >> N;
	
	char tmp;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			int len = 0;
			if (tmp >= 'a' && tmp <= 'z') len = tmp - 'a' + 1;
			else if (tmp >= 'A' && tmp <= 'Z') len = tmp - 'A' + 27;
			//map[i][j] = len;

			//cout << "len : " << len << '\n';
			if (len == 0) continue;

			v.push_back({ len, {i, j} });
			total += len;
		}
	}

	sort(v.begin(), v.end());

	connect();

	int comp = find(1);
	for (int i = 2; i <= N; i++) {
		if (find(i) != comp) {
			cout << -1 << '\n';
			return 0;
		}
	}
	
	cout << total << '\n';
}