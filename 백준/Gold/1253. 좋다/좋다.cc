#include <iostream>
#include <algorithm>
#define MAX 2001
using namespace std;

long long num[MAX] = { 0 };
int result = 0;

int main() {
	int N; cin >> N;
	
	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num, num + N);

	for (int i = 0; i < N; i++) {
		long long target = num[i];

		int start = 0;
		int end = N - 1;

		while (start < end) {
			long long temp = num[start] + num[end];

			if (temp == target) {
				if (start != i && end != i) {
					result++;
					break;
				}
				else if (start == i) start++;
				else if (end == i) end--;
			}
			else if (temp > target) end--;
			else start++;
		}
	}

	cout << result << '\n';
}