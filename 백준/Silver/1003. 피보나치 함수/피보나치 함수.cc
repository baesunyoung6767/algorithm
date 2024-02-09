#include <iostream>
using namespace std;

int T, N;
int dp0[41] = { 0 };
int dp1[41] = { 0 };

void fibo() {
	dp0[0] = 1;
	dp1[1] = 1;

	for (int i = 2; i <= N; i++) {
		dp0[i] = dp0[i - 1] + dp0[i - 2];
		dp1[i] = dp1[i - 1] + dp1[i - 2];
	}
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		fibo();
		cout << dp0[N] << " " << dp1[N] << '\n';
	}
	return 0;
}
