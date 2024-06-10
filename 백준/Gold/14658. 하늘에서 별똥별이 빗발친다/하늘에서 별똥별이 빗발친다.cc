#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, L, K;
vector<pair<int, int>> star;
int result = -1;

int main() {
	cin >> N >> M >> L >> K;

	int temp_x, temp_y;
	for (int i = 0; i < K; i++) {
		cin >> temp_x >> temp_y;
		star.push_back({ temp_x, temp_y });
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			int cx = star[i].first;
			int cy = star[j].second;
			int cnt = 0;

			for (int k = 0; k < K; k++) {
				int nx = star[k].first;
				int ny = star[k].second;

				if (cx <= nx && cx + L >= nx && cy <= ny && cy + L >= ny) cnt++;
			}
			result = max(cnt, result);
		}
	}

	cout << K - result << '\n';
}