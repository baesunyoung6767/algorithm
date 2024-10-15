#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	
	cin >> T;

	while (T--) {
		int N;
		int tree[MAX] = { 0 };
		int result = -1;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> tree[i];
		}

		sort(tree, tree + N);
		result = max(result, tree[1] - tree[0]);
		result = max(result, tree[N - 1] - tree[N - 2]);

		for (int i = 0; i < N - 2; i++) {
			result = max(result, tree[i + 2] - tree[i]);
		}
		cout << result << '\n';
	}
}