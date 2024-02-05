#include <iostream>
using namespace std;

int N, M;
int result[101] = { 0 };

void checkFuc(int cnt, int start) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) cout << result[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = start; i <= N; i++) {
		result[cnt] = i;
		checkFuc(cnt + 1, i + 1);
	}
}

int main() {
	cin >> N >> M;

	checkFuc(0, 1);
	
}
