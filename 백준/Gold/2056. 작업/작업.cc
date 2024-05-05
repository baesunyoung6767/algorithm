#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int N;
vector<int>v[MAX];
int parent[MAX] = { 0 };
int time[MAX] = { 0 };
int result[MAX] = { 0 };
int output = -1;

int main() {
	cin >> N;

	int t, cnt;
	for (int i = 1; i <= N; i++) {
		cin >> t >> cnt;
		time[i] = t;

		int temp;
		for (int j = 0; j < cnt; j++) {
			cin >> temp;
			v[temp].push_back(i);
			parent[i]++;
		}
	}

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (parent[i] == 0) q.push(i);
		result[i] = time[i];
	}

	for (int i = 1; i <= N; i++) {
		if (q.empty()) break; // 실패

		int cur = q.front();
		q.pop();

		for (int j = 0; j < v[cur].size(); j++) {
			int next = v[cur][j];
			result[next] = max(result[next], result[cur] + time[next]);
			parent[next]--;

			if (parent[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= N; i++) {
		output = max(output, result[i]);
	}

	cout << output << '\n';
}