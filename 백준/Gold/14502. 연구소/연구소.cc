#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int N, M;
int map[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
int copyMap[MAX][MAX] = { 0 };

int selected[MAX] = { 0 };
vector<pair<int, int>> v;

int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };
int result = -1;

// 0인 곳에 벽 세우기 -> 조합
// 하나의 경우의 수에 대해서 바이러스 퍼지는 거 탐색 -> 안전 영역 최대값 구하기
void bfs() {
	queue<pair<int, int>> q;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copyMap[i][j] == 2) q.push({ i, j });
		}
	}

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (copyMap[ny][nx] == 0) {
				copyMap[ny][nx] = 2;
				q.push({ ny, nx });
			}
		}
	}
}

void selectWall(int cnt, int start) {
	if (cnt == 3) {
		// 벽 3개 선택 완료

		// map 백업
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copyMap[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < 3; i++) {
			int idx = selected[i];
			int cy = v[idx].first;
			int cx = v[idx].second;
			copyMap[cy][cx] = 1;
		}

		// bfs 탐색으로 안전 영역 구하기
		bfs();

		// 결과 계산
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copyMap[i][j] == 0) cnt++;
			}
		}

		result = max(result, cnt);
		return;
	}

	for (int i = start; i < v.size(); i++) {
		selected[cnt] = i;
		selectWall(cnt + 1, i + 1);
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) v.push_back({ i,j });
		}
	}
	
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				selectWall(0);
				map[i][j] = 0;
			}
		}
	}*/
	selectWall(0, 0);
	cout << result << '\n';
}