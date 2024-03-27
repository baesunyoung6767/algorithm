#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
int price[5001] = { 0 };

int main() {
	cin >> N >> C;
	
	for (int i = 0; i < N; i++) cin >> price[i];
	sort(price, price + N);
	
	bool isPos = false;
	for (int i = 0; i < N; i++) {
		int start = i + 1;
		int end = N - 1;

		while (start < end) {
			int sum = price[i] + price[start] + price[end];
			int sum1 = price[i] + price[start];
			int sum2 = price[i] + price[end];
			int sum3 = price[start] + price[end];

			if (sum == C || sum1 == C || sum2 == C || sum3 == C || price[i] == C || price[start] == C || price[end] == C) {
				isPos = true;
				break;
			}

			if (sum < C) {
				start++;
			}
			else {
				end--;
			}
		}
		
	}

	if (isPos) cout << 1 << '\n';
	else cout << 0 << '\n';
	return 0;
}