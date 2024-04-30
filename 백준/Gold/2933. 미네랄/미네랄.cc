#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <vector>
#define MAX 101
using namespace std;

int R, C, T;
char map[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

vector<pair<int, int>> target;

void init() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			visited[i][j] = 0;
		}
	}
}

void find(int startY, int startX) {
	// 바닥에서부터 탐색 
	queue<pair<int, int>> q;
	q.push({ startY, startX });
	visited[startY][startX] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 1 || nx < 1 || ny > R || nx > C || visited[ny][nx] == 1 || map[ny][nx] == '.') continue;
			visited[ny][nx] = 1;
			q.push({ny, nx});
		}
	}
}

void down() {
	int move = R;
	for (int i = 1; i <= C; i++) {
		for (int j = R; j >= 1; j--) {
			if (map[j][i] == 'x' && visited[j][i] == 0) { // 공중에 있는 미네랄
				int h = 0;
				for (int k = j + 1; k <= R; k++) {
					if (map[k][i] == 'x' && visited[k][i] == 1) {
						move = min(h, move);
						break;
					}
					else h++;
				}
				/*cout << "3-2. h : " << h << '\n';*/
				move = min(h, move);
			}
		}
	}

	
	//cout << "3. move 값 : " << move << '\n';
	for (int i = 1; i <= C; i++) {
		for (int j = R; j >= 1; j--) {
			if (map[j][i] == 'x' && visited[j][i] == 0) {
				map[j + move][i] = 'x';
				map[j][i] = '.';
			}
		}
	}
}

int main() {
	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}
	}

	cin >> T;

	int row;
	for (int t = 1; t <= T; t++) {
		cin >> row;

		if (t % 2 == 0) {  // 오른쪽에서 던짐
			// x 나올 때까지 탐색
			for (int i = C; i >=1; i--) {
				if (map[R - row + 1][i] == 'x') {
					map[R - row + 1][i] = '.';
					break;
				}
			}
		}
		else {
			for (int i = 1; i <= C; i++) {
				if (map[R - row + 1][i] == 'x') {
					map[R - row + 1][i] = '.';
					break;
				}
			}
		}

		//cout << "1. 막대기 던지기 \n";
		//for (int i = 1; i <= R; i++) {
		//	for (int j = 1; j <= C; j++) {
		//		cout << map[i][j];
		//	}
		//	cout << '\n';
		//}

		//cout << '\n';
		// 클러스터가 공중에 있는지
		for (int i = 1; i <= C; i++) {
			if (map[R][i] == 'x' && visited[R][i] == 0) {
				find(R, i);
			}
		}

		/*cout << "2. 공중에 있는 미네랄 찾기 \n";
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				cout << visited[i][j];
			}
			cout << '\n';
		}
		cout << '\n';*/
		// x 내리기
		down();

		/*cout << "4. 공중에 있는 미네랄 내리기 \n";
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}
		cout << '\n';*/
		init();
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}