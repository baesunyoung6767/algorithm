#include <iostream>
using namespace std;

int N;
int visited[1001] = { 0 };
int selected[21] = { 0 };
int arr[4] = { 1, 5, 10, 50 };

void check(int cnt, int start) {
	if (cnt == N) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += selected[i];
		}
		visited[sum] = 1;
		return;
	}

	for (int i = start; i < 4; i++) {
		selected[cnt] = arr[i];
		check(cnt + 1, i);
	}
}

int main() {
	cin >> N;
	check(0, 0);

	int result = 0;
	for (int i = 0; i < 1001; i++) {
		if (visited[i] == 1) result++;
	}
	cout << result << '\n';
	return 0;
}