#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;

int N, M;
int map[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
int result = -1;
int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

int x2[] = { 1, 0 };
int y2[] = { 0, 1 };

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
}

void check(int cy, int cx, int depth, int sum) {
	if (depth == 3) {
		result = max(result, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = cy + y[i];
		int nx = cx + x[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] == 1) continue;
		visited[ny][nx] = 1;
		check(ny, nx, depth + 1, sum + map[ny][nx]);
		visited[ny][nx] = 0;
	}
}

void check2(int cy, int cx, int depth, int sum, int dir) {
	if (depth == 2) {
		int tempSum = -1, ny, nx;
		if (dir == 0) {
			// ㅜ
			ny = cy + 1;
			nx = cx - 1;
			if (ny >= 0 && nx >= 0 && ny < N && nx < M) {
				tempSum = max(tempSum, sum + map[ny][nx]);
			}

			// ㅗ
			ny = cy - 1;
			nx = cx - 1;
			if (ny >= 0 && nx >= 0 && ny < N && nx < M) {
				tempSum = max(tempSum, sum + map[ny][nx]);
			}
		}
		else {
			// ㅏ
			ny = cy - 1;
			nx = cx + 1;
			if (ny >= 0 && nx >= 0 && ny < N && nx < M) {
				tempSum = max(tempSum, sum + map[ny][nx]);
			}

			// ㅓ
			ny = cy - 1;
			nx = cx - 1;
			if (ny >= 0 && nx >= 0 && ny < N && nx < M) {
				tempSum = max(tempSum, sum + map[ny][nx]);
			}
		}

		result = max(result, tempSum);
		return;
	}

	for (int i = 0; i < 2; i++) {
		if (depth == 1 && dir != i) continue;

		int ny = cy + y2[i];
		int nx = cx + x2[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] == 1) continue;
		visited[ny][nx] = 1;
		check2(ny, nx, depth + 1, sum + map[ny][nx], i);
		visited[ny][nx] = 0;
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 1;
			check(i, j, 0, map[i][j]);
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 1;
			check2(i, j, 0, map[i][j], 0);
			visited[i][j] = 0;
		}
	}

	cout << result << "\n";
}