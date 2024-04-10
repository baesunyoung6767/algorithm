#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 201
using namespace std;

int map[MAX][MAX] = { 0 };
int K, W, H;

int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

int x2[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int y2[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int visited[MAX][MAX][31] = { 0 };
int result = 987654321;

void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0, 0}, {0, 0} });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int len = q.front().second.first;
		int use = q.front().second.second;
		q.pop();

		if (cy == H - 1 && cx == W - 1) {
			result = len;
			break;
		}

		if (use < K) {
			for (int i = 0; i < 8; i++) {
				int ny = cy + y2[i];
				int nx = cx + x2[i];

				if (ny < 0 || nx < 0 || ny >= H || nx >= W || visited[ny][nx][use + 1] == 1 || map[ny][nx] == 1) continue;
				visited[ny][nx][use + 1] = 1;
				q.push({ {ny, nx}, {len + 1, use + 1} });
			}
		}
		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 0 || nx < 0 || ny >= H || nx >= W || visited[ny][nx][use] == 1 || map[ny][nx] == 1) continue;
			visited[ny][nx][use] = 1;
			visited[ny][nx][use] = 1;
			q.push({ {ny, nx}, {len + 1, use} });
		}
	}
}
int main() {
	cin >> K >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

	bfs();
	if (result == 987654321) cout << -1 << '\n';
	else cout << result << '\n';
}