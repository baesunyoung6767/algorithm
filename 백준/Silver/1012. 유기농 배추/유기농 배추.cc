#include <iostream>
#include <algorithm>

#define MAX 51
using namespace std;

int cabbage[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
int M, N, K; // 배추밭 가로 길이, 세로 길이, 배추 개수
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

// 인접한 배추에 대해서도 배추흰지렁이의 영향이 있음
// 인접한 배추밭은 하나로 보고 배추밭의 개수 == 필요한 배추흰지렁이 개수

void reset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cabbage[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void graph(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= M || ny < 0 || ny >= N) 
			continue;

		if (cabbage[ny][nx] == 1 && visited[ny][nx] == 0)
			graph(ny, nx);
	}
}

int main() {
	int T; // 테스트 케이스 개수
	cin >> T;

	while (T--) {
		reset();

		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			cabbage[b][a] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cabbage[i][j] == 1 && visited[i][j] == 0) {
					graph(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}