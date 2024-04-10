#include <iostream>
#include <queue>
#include <stack>
using namespace std;

char map[12][6];

int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

int result = 0;

void move() {
	stack<char> s;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 12; j++) {
			if (map[j][i] != '.') {
				s.push(map[j][i]);
				map[j][i] = '.';
			}
		}

		for (int j = 11; j >= 0; j--) {
			if (s.empty()) break;
			map[j][i] = s.top();
			s.pop();
		}
	}

	/*cout << "\n-------------\n";
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}*/
}

bool find(char target, int startY, int startX) {
	int copyMap[12][6];

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			copyMap[i][j] = map[i][j];
		}
	}

	queue<pair<int, int>> q;
	int visited[12][6] = { 0 };
	q.push({ startY, startX });
	visited[startY][startX] = 1;
	copyMap[startY][startX] = '.';
	int cnt = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];
			if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6 || visited[ny][nx] == 1 || copyMap[ny][nx] == '.' || copyMap[ny][nx] != target) continue;
			cnt++;
			q.push({ ny, nx });
			visited[ny][nx] = 1;
			copyMap[ny][nx] = '.';
		}
	}

	if (cnt >= 4) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				map[i][j] = copyMap[i][j];
			}
		}
		/*cout << "\n-------------\n";
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}*/
		return true;
	}
	return false;
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		int pop = 0;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] == 'R' || map[i][j] == 'Y' || map[i][j] == 'G' || map[i][j] == 'P' || map[i][j] == 'B') {
					if (find(map[i][j], i, j)) {
						pop++;
					}
				}
			}
		}
		if (pop == 0) break;
		else {
			result++;
			move();
		}
	}

	cout << result << '\n';
}