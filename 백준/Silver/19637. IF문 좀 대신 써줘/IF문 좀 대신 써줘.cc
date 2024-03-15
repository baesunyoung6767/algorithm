#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
string character[100001];
int power[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> character[i] >> power[i];


	for (int i = 0; i < M; i++) {
		int checkPower;
		cin >> checkPower;

		long long start = 0;
		long long end = N - 1;
		long long mid = 0;

		while (start <= end) {
			mid = (start + end) / 2;
			if (checkPower > power[mid]) start = mid + 1;
			else end = mid - 1;
		}
		if (power[mid] < checkPower) mid++;

		cout << character[mid] << '\n';
	}
}