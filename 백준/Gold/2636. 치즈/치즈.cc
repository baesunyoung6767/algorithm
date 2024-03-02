#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int N, M;
int arr[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
int target = 0;

int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
}

int check() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;
	int temp = 0;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] == 1) continue;

			if (arr[ny][nx] == 0) {
				q.push({ ny, nx });
			}
			else if (arr[ny][nx] == 1) {
				arr[ny][nx] = 0;
				temp++;
			}
			visited[ny][nx] = 1;
		}
	}
	return temp;
}
	
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) target++;
 		}
	}

	int result = 0, left = 0;
	while (1) {
		result++;
		int temp = check();
		target -= temp;
		if (target == 0) {
			left = temp;
			break;
		}
		init();
	}

	cout << result << '\n' << left << '\n';
}