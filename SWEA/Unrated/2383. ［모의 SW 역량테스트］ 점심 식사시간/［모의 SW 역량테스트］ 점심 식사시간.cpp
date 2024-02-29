#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int N;
int map[MAX][MAX] = { 0 };
bool selected[MAX] = { 0 };

vector<pair<int, int>> v; // 사람 위치 저장
vector<pair<int, int>> stairA;
vector<pair<int, int>> stairB;

int X1, Y1, X2, Y2;
int result = 987654321;

void init() {
	result = 987654321;
	v.clear();
	stairA.clear();
	stairB.clear();

	for (int i = 0; i < N; i++) {
		selected[i] = false;
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}
}

int moveStair(vector<pair<int, int>> stairInfo) {
	int t = stairInfo[0].first;

	while (1) {
		int done = 0;
		int cnt = 3;
		bool finish = false;

		for (int i = 0; i < stairInfo.size(); i++) {
			if (cnt > 0) {
				if (stairInfo[i].second == 0) {
					done++;
					if (done == stairInfo.size()) {
						finish = true;
					}
					continue;
				}
				if (stairInfo[i].first < t) {
					stairInfo[i].second--;
					cnt--;
					if (stairInfo[i].second == 0 && stairInfo.size() - (i + 1) > 3) cnt++;
				}
			}
		}
		if (finish) break;
		t++;
	}
	return t;
}

void calcDis() {
	// true라면 1번 계단으로 false라면 2번 계단으로
	stairA.clear();
	stairB.clear();

	for (int i = 0; i < v.size(); i++) {
		int dis = 0;
		if (selected[i]) {
			dis = abs(v[i].first - Y1) + abs(v[i].second - X1);
			stairA.push_back({ dis, map[Y1][X1] });
		}
		else {
			dis = abs(v[i].first - Y2) + abs(v[i].second - X2);
			stairB.push_back({ dis, map[Y2][X2] });
		}
	}

	// stair 정렬
	sort(stairA.begin(), stairA.end());
	sort(stairB.begin(), stairB.end());

	// 시간 계산
	int resultA = 0, resultB = 0;
	if (stairA.size() != 0) resultA = moveStair(stairA);
	if (stairB.size() != 0) resultB = moveStair(stairB);

	// 최소 시간 계산
	result = min(result, max(resultA, resultB));
}

void checkStair(int cnt) {
	if (cnt == v.size()) {
		calcDis();
		return;
	}

	selected[cnt] = true;
	checkStair(cnt + 1);
	selected[cnt] = false;
	checkStair(cnt + 1);
}

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		X1 = X2 = Y1 = Y2 = -1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					v.push_back({ i, j });
				}
				else if (map[i][j] >= 2) {
					if (X1 == -1 && Y1 == -1) {
						Y1 = i; X1 = j;
					}
					else {
						Y2 = i; X2 = j;
					}
				}
			}
		}

		checkStair(0);
		cout << "#" << t << " " << result << '\n';
		init();
	}
}