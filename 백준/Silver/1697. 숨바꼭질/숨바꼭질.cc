#include<iostream>
#include<queue>

using namespace std;

#define MAX 100001

int N, K;
bool visit[MAX];

int BFS(int N, int K) {
	queue<pair <int, int>> que;
	que.push(make_pair(N, 0));
	visit[N] = true;

	while (!que.empty()) {
		int Line = que.front().first;
		int time = que.front().second;
		que.pop();

		if (Line == K)	return time;

		if (Line + 1 < MAX && !visit[Line + 1]) {
			que.push(make_pair(Line + 1, time + 1));
			visit[Line + 1] = true;
		}
		if (Line - 1 >= 0 && !visit[Line - 1]) {
			que.push(make_pair(Line - 1, time + 1));
			visit[Line - 1] = true;
		}
		if (Line * 2 < MAX && !visit[Line * 2]) {
			que.push(make_pair(Line * 2, time + 1));
			visit[Line * 2] = true;
		}
	}
}

int main() {
	cin >> N >> K;

	cout << BFS(N, K) << endl;
	return 0;
}