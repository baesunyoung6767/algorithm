#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K; // 행성 개수, 행성 위치
int arr[11][11];
int visited[11] = { 0 };

int result = 987654321;

void check(int node, int sum, int depth) {
	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		check(i, sum + arr[node][i], depth + 1);
		visited[i] = 0;
	}

	if (depth == N) result = min(result, sum);
}

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
	
		}
	}
	 
	for (int k = 0; k < N; k++) { 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == k || j == k) continue;
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	visited[K] = 1;
	check(K, 0, 1);
	cout << result << '\n';
	return 0;
}