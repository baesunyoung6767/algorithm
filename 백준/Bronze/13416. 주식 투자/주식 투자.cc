#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T; cin >> T;
	int N;

	while (T--) {
		cin >> N;

		int result = 0;
		int A, B, C;
		for (int i = 0; i < N; i++) {
			cin >> A >> B >> C;
			
			int maxNum = max(A, max(B, C));
			if (maxNum < 0) continue;
			result += maxNum;
		}
		cout << result << '\n';
	}
}