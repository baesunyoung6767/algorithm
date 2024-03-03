#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

// 회사 - 고객 - 집 이런식으로 모든 경로 탐색해서 비교

int N; // 고객의 수
int homeX, homeY, comX, comY;
vector<pair<int, int>> customer;
int selected[101];
int visited[101];
int result = 987654321;

void init() {
	for (int i = 0; i < N; i++) {
		selected[i] = 0;
		visited[i] = 0;
	}
	customer.clear();
	result = 987654321;
}

void check(int cnt) {
	if (cnt == N) {
		// 하나의 경우의 수에 대해 경로 계산하기
		int dis = abs(comX - customer[selected[0]].first) + abs(comY - customer[selected[0]].second);

		for (int i = 0; i < N-1; i++) {
			int temp = abs(customer[selected[i]].first - customer[selected[i+1]].first) + abs(customer[selected[i]].second - customer[selected[i+1]].second);
			dis += temp;
		}

		dis += abs(customer[selected[N-1]].first - homeX) + abs(customer[selected[N-1]].second - homeY);

		result = min(result, dis);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		selected[cnt] = i;
		check(cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		cin >> comX >> comY >> homeX >> homeY;
		int posX, posY;
		for (int i = 0; i < N; i++) {
			cin >> posX >> posY;
			customer.push_back({ posX, posY });
		}

		check(0);
		cout << "#" << t << " " << result << '\n';
        init();
	}
}