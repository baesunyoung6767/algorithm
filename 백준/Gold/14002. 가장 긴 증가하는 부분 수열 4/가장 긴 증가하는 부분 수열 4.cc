#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

// 반례
//4
//1 20 30 7
//3
//1 7 30 (X) 1 20 30 (O)

int main() {
	int N;
	cin >> N;
	vector<int> v;
	int dp[MAX] = { 0 };
	int arr[MAX] = { 0 };
	int maxLen = 1;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
			}
			if (maxLen < dp[i]) maxLen = dp[i];
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		if (dp[i] == maxLen) {
			v.push_back(arr[i]);
			maxLen--;
		}
	}

	cout << v.size() << '\n';
	for (int i = v.size()-1; i >= 0; i--) cout << v[i] << ' ';
	cout << '\n';
}