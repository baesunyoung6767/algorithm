#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> v[32001];
int len[32001] = { 0 };
queue<int> q;

void check() {
	for (int i = 1; i <= N; i++) {
		if (len[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int num = q.front();
		cout << num << ' ';
		q.pop();

		for (int i = 0; i < v[num].size(); i++) {
			int next = v[num][i];
			len[next]--;
			if (len[next] == 0) q.push(v[num][i]);
		}
	}
	cout << '\n';
}

int main() {
	cin >> N >> M;
	
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		len[b]++;
	}

	check();
}