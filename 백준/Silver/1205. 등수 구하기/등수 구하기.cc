#include <iostream>
using namespace std;

int N, S, P; // S : 태수의 점수
int score[51] = { 0 };
int rank_arr[51] = { 0 };

int main() {
	cin >> N >> S >> P;
	
	for (int i = 0; i < N; i++) cin >> score[i];

	int rank_cnt = 1;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (score[i] > S) rank_cnt++;
		else if (score[i] == S) rank_cnt = rank_cnt;
		else break;
		cnt++;
	}

	if (cnt == P) rank_cnt = -1;
	if (N == 0) rank_cnt = 1;

	cout << rank_cnt << '\n';
}