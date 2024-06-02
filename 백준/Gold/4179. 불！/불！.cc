#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

char map[MAX][MAX] = { 0 };
int fire_map[MAX][MAX] = { 0 };

int R, C;
int result = -1;

queue<pair<pair<int, int>, int>> jh;
queue<pair<int, int>> fire;

void move_fire() {
	int visited[MAX][MAX] = { 0 };

	while (!fire.empty()) {
		int cy = fire.front().first;
		int cx = fire.front().second;
		fire.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if (map[ny][nx] == '#' || visited[ny][nx] == 1) continue;

			visited[ny][nx] = 1;
			fire.push({ ny, nx });
			fire_map[ny][nx] = fire_map[cy][cx] + 1;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (fire_map[i][j] == 0) fire_map[i][j] = 987654321;
		}
	}

	//for (int i = 0; i < R; i++) {
	//	for (int j = 0; j < C; j++) {
	//		cout << map[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
}

void move_jh() {
	int visited[MAX][MAX] = { 0 };

	while (!jh.empty()) {
		int cy = jh.front().first.first;
		int cx = jh.front().first.second;
		int cnt = jh.front().second;
		jh.pop();
		visited[cy][cx] = 1;

		if (cy == 0 || cx == 0 || cy == R - 1 || cx == C - 1) {
			result = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if (map[ny][nx] == '#' || visited[ny][nx] == 1) continue;
			if (fire_map[ny][nx] <= cnt + 1) continue;
			jh.push({ {ny, nx}, cnt + 1 });
            visited[ny][nx] = 1;
		}
	}
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'J') jh.push({ {i,j}, 1 });
			if (map[i][j] == 'F') {
				fire.push({ i,j });
				fire_map[i][j] = 1;
				map[i][j] = '#';
			}
		}
	}

	// 불 먼저 이동하고
	move_fire();
	// 지훈이 이동
	move_jh();

	if (result == -1) cout << "IMPOSSIBLE\n";
	else cout << result << '\n';
}