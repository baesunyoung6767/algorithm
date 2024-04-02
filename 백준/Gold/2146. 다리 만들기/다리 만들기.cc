#include <iostream>
#include <queue>
#include<algorithm>
#define MAX 101
using namespace std;

int N;
int map[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

int idx = 1;
int minLen = 987654321;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) visited[i][j] = 0;
	}
}

void checkLen(int startY, int startX) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { startY, startX }, 0 });
	visited[startY][startX] = 1;
	int curIsland = map[startY][startX];

	while (!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int clen = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] == 1) continue;

			if (map[ny][nx] == 0) {
				q.push({ { ny, nx }, clen + 1 });
				visited[ny][nx] = 1;
			}
			else if (map[ny][nx] != curIsland) {
				minLen = min(minLen, clen);
			}
		}
	}
}

void island(int startY, int startX) {
	queue<pair<int, int>> q;
	q.push({ startY, startX });
	visited[startY][startX] = 1;
	map[startY][startX] = idx;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] == 1 || map[ny][nx] == 0) continue;
			map[ny][nx] = idx;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				island(i, j);
				idx++;
			}
		}
	}
	init();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0) checkLen(i, j);
			init();
		}
	}

	cout << minLen << '\n';
}