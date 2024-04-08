#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 21
using namespace std;

int N;
int map[MAX][MAX] = { 0 };
int result = 987654321;
int copyMap[MAX][MAX] = { 0 };

int getOne(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (copyMap[i][j] != 5) {
				copyMap[i][j] = 1;
				sum += map[i][j];
			}
		}
	}
	return sum;
}

int getTwo(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int i = 1; i <= x + d2; i++) {
		for (int j = y + 1; j <= N; j++) {
			if (copyMap[i][j] != 5) {
				copyMap[i][j] = 2;
				sum += map[i][j];
			}
		}
	}
	return sum;
}

int getThree(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int i = x+d1; i <= N; i++) {
		for (int j = 1; j < y-d1+d2; j++) {
			if (copyMap[i][j] != 5) {
				copyMap[i][j] = 3;
				sum += map[i][j];
			}
		}
	}
	return sum;
}

int getFour(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int i = x + d2 + 1; i <= N; i++) {
		for (int j = y-d1+d2; j <= N; j++) {
			if (copyMap[i][j] != 5) {
				copyMap[i][j] = 4;
				sum += map[i][j];
			}
		}
	}
	return sum;
}

bool check(int r, int c) {
	if (r< 1 || c < 1 || r>N || c > N) return false;
	return true;
}

bool div(int x, int y, int d1, int d2) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			copyMap[i][j] = 0;
		}
	}

	copyMap[x][y] = 5;
	int cr = x;
	int cc = y;

	for (int k = 0; k < d1; k++) {
		int nr = cr + 1;
		int nc = cc - 1;
		if (!check(nr, nc)) return false;
		cr = nr;
		cc = nc;
		for (int col = nc; col <= y; col++) copyMap[nr][col] = 5;
	}

	cr = x;
	cc = y;
	for (int k = 0; k < d2; k++) {
		int nr = cr + 1;
		int nc = cc + 1;
		if (!check(nr, nc)) return false;
		cr = nr;
		cc = nc;
		for (int col = y; col <= nc; col++) copyMap[nr][col] = 5;
	}

	cr = x + d1;
	cc = y - d1;
	for (int k = 0; k < d2; k++) {
		int nr = cr + 1;
		int nc = cc + 1;
		if (!check(nr, nc)) return false;
		cr = nr;
		cc = nc;
		for (int col = nc; col <= y - d1 + d2; col++) copyMap[nr][col] = 5;
	}

	cr = x + d2;
	cc = y + d2;
	for (int k = 0; k < d1; k++) {
		int nr = cr + 1;
		int nc = cc - 1;
		if (!check(nr, nc)) return false;
		cr = nr;
		cc = nc;
		for (int col = y - d1 + d2; col <= nc; col++) copyMap[nr][col] = 5;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	int total = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			total += map[i][j];
		}
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= 18; d1++) {
				for (int d2 = 1; d2 <= 18; d2++) {
					if (x + d1 + d2 > N) break;
					if (!div(x, y, d1, d2)) continue;

					int sum1 = getOne(x, y, d1, d2);
					int sum2 = getTwo(x, y, d1, d2);
					int sum3 = getThree(x, y, d1, d2);
					int sum4 = getFour(x, y, d1, d2);
					int sum5 = total - (sum1 + sum2 + sum3 + sum4);
					if (sum1 < 1 || sum2 < 1 || sum3 < 1 || sum4 < 1 || sum5 < 1) continue;

					int maxNum = max(sum1, max(sum2, max(sum3, max(sum4, sum5))));
					int minNum = min(sum1, min(sum2, min(sum3, min(sum4, sum5))));
					
					result = min(result, maxNum - minNum);
				}
			}
		}
	}

	cout << result << '\n';
}