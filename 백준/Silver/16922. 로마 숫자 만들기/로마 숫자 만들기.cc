#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int N, result = 0;
int roma[] = { 1,5,10,50 };
int visited[10001];

void dfs(int cnt, int d, int total) {
	if (cnt == N) {
		if (visited[total] == 0) {
			visited[total] = 1;
			result++;
		}
		return;
	}

	for (int i = d; i < 4; i++) {
		dfs(cnt + 1, i, total + roma[i]);
	}
}

int main() {
	cin >> N;

	dfs(0, 0, 0);
	cout << result << '\n';

}