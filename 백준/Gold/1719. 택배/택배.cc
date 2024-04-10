#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int map[201][201] = { 0 }; // 비용 저장
int num[201][201] = { 0 }; // 집하장 번호

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 987654321;
			if (i == j) map[i][j] = 0;
		}
	}

	int a, b, price;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> price;

		map[a][b] = price;
		map[b][a] = price;
		num[a][b] = b;
		num[b][a] = a;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j || i == k || k == j) continue;

				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
					num[i][j] = num[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (num[i][j] == 0) cout << "- ";
			else cout << num[i][j] << ' ';
		}
		cout << '\n';
	}
}