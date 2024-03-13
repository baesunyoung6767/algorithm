#include <iostream>
#include <queue>
#include <math.h>
#define MAX 51
using namespace std;

int N, L, R;
int country[MAX][MAX] = { 0 }; // 각 나라 인구 수 입력 받기
//int unionArr[MAX][MAX] = { 0 }; // 연합국 체크
int visited[MAX][MAX] = { 0 };

int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}

//void change(int num) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (unionArr[i][j] == 1 && visited[i][j] == 0) {
//				country[i][j] = num;
//				visited[i][j] = 1;
//			}
//		}
//	}
//}

bool bfs(int startY, int startX) {
	int unionCnt = 0;
	queue<pair<int, int>> q;
	queue<pair<int, int>> change;

	change.push({ startY, startX });
	q.push({ startY, startX });
	visited[startY][startX] = 1;
	
	int sum = country[startY][startX], cnt = 1;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] == 1) continue;
			
			int diff = abs(country[cy][cx] - country[ny][nx]);
			if (diff >= L && diff <= R) {
				q.push({ ny, nx });
				change.push({ ny, nx });
				visited[ny][nx] = 1;
				sum += country[ny][nx];
				cnt++;
				unionCnt++;
			}
		}
	}

	// 연합국 인구수 변화
	while (!change.empty()) {
		int targetY = change.front().first;
		int targetX = change.front().second;
		change.pop();
		country[targetY][targetX] = sum / cnt;
	}

	return unionCnt;
}

int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> country[i][j];
		}
	}

	int result = 0;
	// bfs 탐색
	while (1) {
		int continueCheck = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0) {
					continueCheck += bfs(i, j);
				}
			}
		}

		if (continueCheck == 0) break;
		// 연합국 체크 배열 초기화
		init();
		result++;
	}

	cout << result << '\n';
}