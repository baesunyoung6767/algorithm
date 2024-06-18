#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;

int M, N; //집의 수, 길의 수
vector<pair<int, pair<int, int>>> v;
int parents[MAX] = { 0 };
int result = 0;
int total = 0;

void init() {
	v.clear();
	result = 0; total = 0;

	for (int i = 0; i < M; i++) parents[i] = 0;
}

int find(int node) {
	if (parents[node] == node) return node;
	else return parents[node] = find(parents[node]);
}

int main() {
	while (1) {
		cin >> M >> N;

		if (M == 0 && N == 0) return 0;

		int a, b, len;
		for (int i = 0; i < N; i++) {
			cin >> a >> b >> len;
			v.push_back({ len, {a,b} });
			total += len;
		}

		for (int i = 0; i < M; i++) parents[i] = i;

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			int cost = v[i].first;
			int a = v[i].second.first;
			int b = v[i].second.second;

			int pa = find(a);
			int pb = find(b);

			if (pa != pb) {
				if (pa > pb) parents[pa] = pb;
				else parents[pb] = pa;

				result += cost;
			}
		}

		cout << total - result << '\n';
		init();
	}
	
}