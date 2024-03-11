#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int N, M;
int dot[MAX] = { 0 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> dot[i];
	sort(dot, dot + N);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		int start = 0;
		int end = N - 1;
		int mid = 0;

		// a 위치 찾기
		while (start <= end) {
			mid = (start + end) / 2;

			if (dot[mid] < a) start = mid + 1;
			else end = mid - 1;
		}
		int a_location = start;

		// b 위치 찾기
		start = 0; end = N - 1; mid = 0;
		while (start <= end) {
			mid = (start + end) / 2;

			if (dot[mid] > b) end = mid - 1;
			else start = mid + 1;
		}
		int b_location = end;

		cout << b_location - a_location + 1<< '\n';
	}
	return 0;
}