#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 12
using namespace std;

char island[MAX][MAX];
char copyIsland[MAX][MAX];
int R, C;
vector<pair<int, int>> land;

int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

int start_y = 987654321, start_x = 987654321, end_y = -1, end_x = -1;

void init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			island[i][j] = '.';
			copyIsland[i][j] = '.';
		}
	}
}

void copy_island() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			copyIsland[i][j] = island[i][j];
		}
	}
}

void output() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (copyIsland[i][j] == 'X') {
				start_y = min(start_y, i);
				end_y = max(end_y, i);
				start_x = min(start_x, j);
				end_x = max(end_x, j);
			}
		}
	}
}

void after(int yy, int xx) {
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int ny = yy + y[i];
		int nx = xx + x[i];

		if (island[ny][nx] == '.') cnt++;
	}

	if (cnt >= 3) {
		copyIsland[yy][xx] = '.';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init();

	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> island[i][j];
			if (island[i][j] == 'X') {
				land.push_back({ i ,j });
			}
		}
	}

	copy_island();

	for (int i = 0; i < land.size(); i++) {
		int yy = land[i].first;
		int xx = land[i].second;

		after(yy, xx);
	}

	// 출력
	output();
	for (int i = start_y; i <= end_y; i++) {
		for (int j = start_x; j <= end_x; j++) {
			cout << copyIsland[i][j];
		}
		cout << '\n';
	}
}