#include <iostream>
#include <queue>
using namespace std;

int N, M, D;
int map[17][17] = { 0 };
int copyMap[17][17] = { 0 }; // 백업
int check[3] = { 0 }; // 궁수 배치의 하나의 경우의 수

int maxCount = -1;

int x[] = { -1, 0, 1 };
int y[] = { 0, -1, 0 };

void castle(int depth, int start) {
	if (depth == 3) {
		int enemy[17][17] = { 0 };

		// map 복사
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copyMap[i][j] = map[i][j];
			}
		}

		// 하나의 경우의 수에 대해서 
		int idx = N;
		int kill = 0;

		while (idx > 0) {
			// bfs로 가장 가까운 적 탐색
			for (int i = 0; i < 3; i++) {
				int visited[17][17] = { 0 };
				int archerY = idx;
				int archerX = check[i];

				queue <pair<int, int>> q;
				q.push({ archerY - 1, archerX });
				visited[archerY - 1][archerX] = true;

				while (!q.empty()) {
					int cy = q.front().first;
					int cx = q.front().second;
					q.pop();

					if (copyMap[cy][cx] == 1) {
						enemy[cy][cx] = 1;
						break;
					}

					for (int j = 0; j < 3; j++) {
						int ny = cy + y[j];
						int nx = cx + x[j];

						if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] == 1) continue;
						if (abs(archerY - ny) + abs(archerX - nx) <= D) {
							visited[ny][nx] = 1;
							q.push({ ny, nx });
						}
						
					}
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (enemy[i][j] == 1) copyMap[i][j] = 0;
				}
			}
			idx--;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (enemy[i][j] == 1) kill++;
			}
		}

		maxCount = max(kill, maxCount);
		return;
	}

	for (int i = start; i < M; i++) {
		check[depth] = i;
		castle(depth + 1, i + 1);
	}
}

int main() {
	cin >> N >> M >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	castle(0, 0);
	cout << maxCount << '\n';
	return 0;
}