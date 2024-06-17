#include <iostream>
using namespace std;

int child[20] = { 0 };

int main() {
	int T, t;
	cin >> T;
	while (T--) {
		int result = 0;

		cin >> t;
		for (int i = 0; i < 20; i++) cin >> child[i];

		for (int i = 1; i < 20; i++) {
			for (int j = 0; j < i; j++) {
				if (child[j] > child[i]) {
					int temp = child[i];
					for (int k = i; k > j; k--) {
						child[k] = child[k - 1];
						result++;
					}
					child[j] = temp;
					break;
				}
			}
		}
		cout << t << " " << result << '\n';
	}
}