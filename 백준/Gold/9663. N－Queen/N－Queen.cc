#include <iostream>
#include <math.h>
#define MAX 15
using namespace std;

int N;
int arr[MAX] = { 0 };
int result = 0;
void check(int cnt) {
	for (int i = 0; i < cnt; i++) {
		// 같은 열X 같은 행X 대각선 X
		if (arr[i] == arr[cnt] || abs(i - cnt) == abs(arr[i] - arr[cnt])) return;
	}

	if (cnt == N - 1) {
		result++;
		return;
	}

	for (int i = 0; i < N; i++) { // 행 결정
		arr[cnt + 1] = i;
		check(cnt + 1);
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		arr[0] = i;
		check(0);
	}
	cout << result << '\n';
}