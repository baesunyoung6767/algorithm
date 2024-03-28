#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int N;
int map[21][21] = { 0 };
int weight = 2; // 현재 아기 상어 무게
int curY, curX; // 현재 아기 상어 위치
int eat = 0; // 현재 먹은 물고기 개수
int visited[21][21] = { 0 };
int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };

int total = 0;

bool isEat = false;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}

void move(int targetY, int targetX) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { curY, curX }, 0 });
	visited[curY][curX] = 1;
	int eatTime = 0;

	while (!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int time = q.front().second;
		q.pop();
		if (map[cy][cx] < weight && map[cy][cx] != 0 && eatTime == time) {
			if (curY > cy || (curY == cy && curX > cx)) {
				curY = cy; curX = cx; 
				continue;
			}
		}
		
		for (int i = 0; i < 4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] == 1 || map[ny][nx] > weight) continue;

			if (map[ny][nx] < weight && map[ny][nx] != 0 && !isEat) {
				isEat = true;
				curY = ny; curX = nx;
				eatTime = time + 1;
				total += eatTime;
			}
			else {
				visited[ny][nx] = 1;
				q.push({ {ny, nx}, time + 1 });
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				curY = i; curX = j;
				map[i][j] = 0;
			}
		}
	}


	while (1) {
		move(curY, curX);
		if (isEat) {
			isEat = false;
			eat++;
			map[curY][curX] = 0;

			if (weight <= eat) {
				weight++;
				eat = 0;
			}
			init();
		}
		else break;
	}
	cout << total << '\n';
	
}