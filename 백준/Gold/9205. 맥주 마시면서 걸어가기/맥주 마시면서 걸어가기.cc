#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int T, N;
int homeY, homeX;
int festivalY, festivalX;
vector<pair<int, int>> v; // 편의점 위치 담기
int visited[101] = { 0 };

void init() {
	for (int i = 0; i < N; i++) visited[i] = 0;
	v.clear();
}

bool goFestival() {
	queue<pair<int, int>> q;
	q.push({ homeY, homeX });

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		if (abs(festivalY - cy) + abs(festivalX - cx) <= 1000) return true;

		for (int i = 0; i < N; i++) {
			if (visited[i] == 1) continue;
			if (abs(v[i].first - cy) + abs(v[i].second - cx) <= 1000) {
				visited[i] = 1;
				q.push({ v[i].first, v[i].second });
			}
		}
	}
	return false;
}

int main() {
	cin >> T;

	while (T--) {
		cin >> N;

		cin >> homeY >> homeX;
		int tempY, tempX;
		for (int i = 0; i < N; i++) {
			cin >> tempY >> tempX;
			v.push_back({ tempY, tempX });
		}
		cin >> festivalY >> festivalX;


		if (goFestival()) cout << "happy\n";
		else cout << "sad\n";

		init();
	}

}