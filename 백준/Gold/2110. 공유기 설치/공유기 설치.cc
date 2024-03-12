#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 200000;

int N;
int M;
int house[MAX];

bool possible(int len) //4
{
	int cnt = 1;
	int prev = house[0];
	for (int i = 0; i < N; i++) {
		if (house[i] - prev >= len) {
			cnt++;
			prev = house[i];
		}
	}

	if (cnt >= M)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> house[i];
	}
	sort(house, house + N);

	int low = 1, high = house[N - 1] - house[0];
	int result = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
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