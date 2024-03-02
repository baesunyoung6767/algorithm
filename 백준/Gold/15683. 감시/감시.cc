#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int N, M;
int arr[MAX][MAX] = { 0 };
vector<pair<int, int>> v;

int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

int result = 987654321;

void dfs(int dir, int startY, int startX) {
	int cy = startY;
	int cx = startX;

	while (1) {
		int ny = cy + y[dir];
		int nx = cx + x[dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 6) break;
		if (arr[ny][nx] == 0) arr[ny][nx] = 7;
		cy = ny;
		cx = nx;
	}
}

void check(int cnt) {
	if (cnt == v.size()) {
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0) cnt++;
			}
		}

		result = min(result, cnt);
		return;
	}

	
		int tempY = v[cnt].first;
		int tempX = v[cnt].second;
		int kind = arr[tempY][tempX];
		int copyArr[MAX][MAX] = { 0 };

		// 맵 복사
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copyArr[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			switch (kind) {
			case 1:
				dfs((0 + i) % 4, tempY, tempX);
				break;
			case 2:
				dfs((0 + i) % 4, tempY, tempX);
				dfs((2 + i) % 4, tempY, tempX);
				break;
			case 3:
				dfs((0 + i) % 4, tempY, tempX);
				dfs((3 + i) % 4, tempY, tempX);
				break;
			case 4:
				dfs((0 + i) % 4, tempY, tempX);
				dfs((2 + i) % 4, tempY, tempX);
				dfs((3 + i) % 4, tempY, tempX);
				break;
			case 5:
				dfs((0 + i) % 4, tempY, tempX);
				dfs((1 + i) % 4, tempY, tempX);
				dfs((2 + i) % 4, tempY, tempX);
				dfs((3 + i) % 4, tempY, tempX);
				break;
			}

			check(cnt + 1);

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					arr[i][j] = copyArr[i][j];
				}
			}
		}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) 
				if(arr[i][j] != 6) v.push_back({ i,j }); // 카메라 위치 저장
			}
	}
	check(0);
	cout << result << '\n';
}