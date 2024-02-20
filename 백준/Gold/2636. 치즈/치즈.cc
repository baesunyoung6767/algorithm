#include <iostream>
#include <queue>

#define MAX 101
using namespace std;

int N, M;
int arr[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };
int total = 0;
int result = 0;
int hour = 0;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
}

int bfs() {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] == 1) continue;
			if (arr[ny][nx] == 1) {
				arr[ny][nx] = 0;
				cnt++;
			}
			else if (arr[ny][nx] == 0) {
				q.push({ ny,nx });
			}
			visited[ny][nx] = 1;
		}
	}

	return cnt;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) total++;
		}
	}
	
	while (total > 0) {
		hour++;
		int tmp = bfs();
		total -= tmp;
		if (total <= 0) {
			result = tmp;
			break;
		}
		init();
	}

	cout << hour << '\n' << result << '\n';
}