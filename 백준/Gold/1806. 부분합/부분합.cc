#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, S; // N짜리 수열, 합이 S 이상
	int arr[MAX] = { 0 };
	cin >> N >> S;


	for (int i = 0; i < N; i++) cin >> arr[i];

	int left = 0, right = 0;
	int sum = 0;
	int minLen = 987654321;

	while (left <= N && right <= N) {
		if (sum < S) {
			sum += arr[right++];
		}
		else {
			int len = right - left;
			minLen = min(len, minLen);
			sum -= arr[left++];
		}
	}

	if (minLen == 987654321) cout << 0 << '\n';
	else cout << minLen << '\n';
}