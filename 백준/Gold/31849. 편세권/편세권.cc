#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define MAX 1001
using namespace std;

int N, M, R, C; // 지도 크기, 방 개수, 편의점 개수
int map[MAX][MAX] = { 0 };

int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

int result = 987654321;

// 편의점에서부터 탐색
queue<pair<pair<int, int>, pair<int, int>>> q; // first는 편의점 위치
int visited[MAX][MAX] = { 0 };

void bfs() {

	while (!q.empty()) {
		int convX = q.front().first.first;
		int convY = q.front().first.second;
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 1 || nx < 1 || ny > M || nx > N || visited[nx][ny] == 1) continue;
			
			if (map[nx][ny] > 0) {
				int temp_cost = (abs(convX - nx) + abs(convY - ny)) * map[nx][ny];
				result = min(temp_cost, result);
			}
			visited[nx][ny] = 1;
			q.push({ { convX , convY }, { nx, ny } });
		}
	}
}

int main() {
	cin >> N >> M >> R >> C;

	int a, b, p;
	for (int i = 0; i < R; i++) {
		cin >> a >> b >> p;
		map[a][b] = p;
	}

	int c, d;
	for (int i = 0; i < C; i++) {
		cin >> c >> d;
		q.push({ {c, d}, {c, d} });
		visited[c][d] = 1;
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}*/
	bfs();

	cout << result << '\n';
}