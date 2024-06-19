#include <iostream>
#define MAX 100001
using namespace std;

int N, M; // 굴다리 길이, 가로등 개수
int slamp[MAX];

bool isPos(int height) {
	for (int i = 0; i < M; i++) {
		if (i == 0) {
			if (slamp[i] - height > 0) return false;
		}
		if (slamp[i] - height > slamp[i - 1] + height) return false;
		if (i == M - 1) {
			if (slamp[i] + height < N) return false;
		}
	}
	return true;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) cin >> slamp[i];

	int start = 1; // 가로등 높이
	int end = N;
	int mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		// mid 높이가 가능하냐
		if (isPos(mid)) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	cout << start << '\n';
}