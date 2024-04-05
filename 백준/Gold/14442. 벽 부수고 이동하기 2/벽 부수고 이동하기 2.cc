#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

int N, M , K;
int map[MAX][MAX] = { 0 };
int visited[MAX][MAX][11] = { 0 };
int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };
int result = 987654321;

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0, 0}, {1, 0} }); // 위치, 이동 거리, 벽 부순 개수
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int clen = q.front().second.first;
		int wallCnt = q.front().second.second;
		q.pop();
		
		if (cy == N-1 && cx == M-1) {
			result = min(result, clen);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (map[ny][nx] == 0 && visited[ny][nx][wallCnt] == 0) {
				visited[ny][nx][wallCnt] = 1;
				q.push({ {ny, nx}, {clen + 1, wallCnt} });
			}
			else if (map[ny][nx] == 1 && visited[ny][nx][wallCnt - 1] == 0 && wallCnt < K) {
				visited[ny][nx][wallCnt + 1] = 1;
				q.push({ { ny, nx }, { clen + 1, wallCnt + 1 } });
			}
		}
	}
}

int main() {
	cin >> N >> M >> K;

	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < M; j++) {
			map[i][j] = temp[j] - '0';
		}
	}

	bfs();
	if (result == 987654321) cout << -1 << '\n';
	else cout << result << '\n';
}