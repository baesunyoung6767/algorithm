#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;
int result[101][100001] = { 0 };

void init() {
	v.clear();

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 100001; j++) result[i][j] = -1;
	}
}

int dp(int idx, int price) {
	if (price < 0) return 0;
	if (idx == N) return price == 0;
	
	if (result[idx][price] != -1) return result[idx][price];

	for (int i = 0; i <= v[idx].second; i++) {
		result[idx][price] = max(result[idx][price], dp(idx + 1, price - v[idx].first * i));
	}
	return result[idx][price];
}

int main() {
	for (int t = 0; t < 3; t++) {
		cin >> N;
		
		int coinCnt, coinKind, sum = 0;
		init();

		for (int i = 0; i < N; i++) {
			cin >> coinKind >> coinCnt;
			v.push_back({ coinKind, coinCnt });
			sum += coinKind * coinCnt;
		}

		int output = 0;
		if (sum % 2 == 0) {
			output = dp(0, sum / 2);
		}
		cout << output << '\n';
	}
}