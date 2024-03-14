#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000000;

int N;
long long M;
long long tree[MAX];

bool possible(long long len)
{
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		if (tree[i]-len > 0)
			cnt += tree[i] - len;
	}

	if (cnt >= M)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	long long high = 0;

	for (int i = 0; i < N; i++) {
		cin >> tree[i];

		high = max(high, tree[i]);
	}

	long long result = 0;
	long long low = 1;

	while (low <= high) {
		long long mid = (low + high) / 2;
		if (possible(mid)) {
			if (result < mid)
				result = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << result << "\n";
	return 0;
}