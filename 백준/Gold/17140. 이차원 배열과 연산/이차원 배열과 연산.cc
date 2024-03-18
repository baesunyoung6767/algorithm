#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int r, c, k;
int arr[MAX][MAX] = { 0 };
int num[MAX] = { 0 };
int endR = 0, endC = 0; // 행,열 각각 마지막 값이 들어간 인덱스 체크 

void checkSortR(int startR, int startC) {
	for (int i = 1; i <= startR; i++) {
		vector<pair<int, int>> v;
		for (int j = 1; j <= startC; j++) {
			num[arr[i][j]]++;
			arr[i][j] = 0;
		}

		for (int j = 1; j <= 100; j++) {
			if (num[j] != 0) v.push_back({ num[j], j });
		}

		sort(v.begin(), v.end());

		int idx = 1;
		for (int j = 0; j < v.size(); j++) {
			arr[i][idx++] = v[j].second;
			arr[i][idx++] = v[j].first;

			if (idx > 100) break;
		}
		endC = max(idx-1, endC);

		for (int j = 1; j <= 100; j++) {
			num[j] = 0;
		}
	}
}

void checkSortC(int startR, int startC) {
	for (int i = 1; i <= startC; i++) {
		vector<pair<int, int>> v;
		for (int j = 1; j <= startR; j++) {
			num[arr[j][i]]++;
			arr[j][i] = 0;
		}

		for (int j = 1; j <= 100; j++) {
			if (num[j] != 0) v.push_back({ num[j], j });
		}

		sort(v.begin(), v.end());

		int idx = 1;
		for (int j = 0; j < v.size(); j++) {
			arr[idx++][i] = v[j].second;
			arr[idx++][i] = v[j].first;
			if (idx > 100) break;
		}
		endR = max(idx - 1, endR);

		for (int j = 1; j <= 100; j++) {
			num[j] = 0;
		}
	}
}

int main() {
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];

			endR = i;
			endC = j;
		}
	}

	int time = 0, target = 0;
	bool pos = true;
	while (1) {
		if (arr[r][c] == k) break;

		time++;
		if (time > 100) { pos = false; break; }

		if (endR >= endC) checkSortR(endR, endC); // 행 기준 정렬
		else checkSortC(endR, endC); // 열 기준 정렬
	}

	if (!pos) cout << -1 << '\n';
	else cout << time << '\n';
}