#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;

	int low = 1, high = K;
	int result = -1;
	while (low <= high) {
		int cnt = 0;
		int mid = (low + high) / 2;
		for (int i = 1; i <= N; i++)
			cnt += min(mid / i, N);
		if (cnt < K)
			low = mid + 1;
		else {
			result = mid;
			high = mid - 1;
		}
	}
	cout << result << "\n";
	return 0;
}