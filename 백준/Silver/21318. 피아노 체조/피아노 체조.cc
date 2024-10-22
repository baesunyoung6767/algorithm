#include <iostream>
#define MAX 100001
using namespace std;

int N, Q;
long long piano[MAX] = { 0 };
long long check[MAX] = { 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> piano[i];

	for (int i = 1; i < N; i++) {
		if (piano[i + 1] < piano[i]) {
			check[i + 1] = check[i] + 1;
		}
		else {
			check[i + 1] = check[i];
		}
	}

	cin >> Q;

	while (Q--) {
		int x, y;
		cin >> x >> y;

		cout << check[y] - check[x] << '\n';
	}
}