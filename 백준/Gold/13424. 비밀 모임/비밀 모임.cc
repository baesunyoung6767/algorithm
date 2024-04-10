#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int main() {
	int T; cin >> T;

	while (T--) {
		int N, M; // 방의 개수, 비밀통로 개수
		int room[MAX][MAX] = { 0 };
		int selected[MAX] = { 0 };

		cin >> N >> M;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (room[i][j] == 0) room[i][j] = 987654321;
				if (i == j) room[i][j] = 0;
			}
		}

		int a, b, price;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> price;
			room[a][b] = price;
			room[b][a] = price;
		}

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (k == i || i == j || k == j) continue;
					room[i][j] = min(room[i][j], room[i][k] + room[k][j]);
				}
			}
		}

		int K; cin >> K;
		int temp;
		for (int i = 0; i < K; i++) {
			cin >> temp;
			selected[temp] = 1;
		}

		int result[MAX] = { 0 };
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (selected[i] == 1) {
					result[j] += room[i][j];
				}
			}
		}

		int minNum = 987654321, minResult = 987654321;
		for (int i = 1; i <= N; i++) {
			if (result[i] < minResult) {
				minResult = result[i];
				minNum = i;
			}
		}
		cout << minNum << '\n';
	}
}