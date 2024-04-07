// 다리 만들기2
// mst 코드 문제 인 것 같은데 10%에서 계속 틀려서 코드 수정 필요ㅠㅠ
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[11][11] = { 0 };
int visited[11][11] = { 0 };
int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };
vector<pair<int, pair<int, int>>> v;
int parent[7] = { 0 };
int result = 0;
int checked[7] = { 0 };

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
}

int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}

void move(int startY, int startX) {
	int startNum = map[startY][startX];

	for (int i = 0; i < 4; i++) {
		int cy = startY;
		int cx = startX;
		int moveCnt = 0;
		while (1) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) break;

			if (map[ny][nx] == startNum) break;
			else if (map[ny][nx] == 0) {
				cy = ny;
				cx = nx;
				moveCnt++;
			}
			else if (moveCnt >= 2 && map[ny][nx] != startNum) {
				v.push_back({ moveCnt, {startNum, map[ny][nx]} });
				break;
			}
			else break;
		}
	}

}

// 섬 번호 체크
void islandNum(int idx, int startY, int startX) {
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

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] == 1 || map[ny][nx] == 0) continue;

			map[ny][nx] = idx;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;
		}
	}

	// 섬 번호 부여
	int idx = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == -1) {
				islandNum(idx, i, j);
				idx++;
				init();
			}
		}
	}

	// 모든 섬에서 이동
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0) {
				move(i, j);
			}
		}
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= idx - 1; i++) parent[i] = i;

	/*for (int i = 0; i < v.size(); i++) {
		cout << v[i].second.first << " -> " << v[i].second.second << " : " << v[i].first << '\n';
	}*/

	for (int i = 0; i < v.size(); i++) {
		int a = find(v[i].second.first);
		int b = find(v[i].second.second);
		int price = v[i].first;

		if (a != b) {
			result += price;
			if (a < b) parent[b] = a;
			else parent[a] = b;
			//checked[a] = 1;
			//checked[b] = 1;
		}
	}

	// 모든 섬들이 연결되었는지 확인

	for (int i = 1; i <= idx - 1; i++) {
		if (find(i) != 1) {
			cout << -1 << '\n';
			return 0;
		}
	}

	cout << result << '\n';
}