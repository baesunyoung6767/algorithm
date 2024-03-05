#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K;
string word[51];
int selected[27];

int result = -1;
bool checked[27];

// 0 == 'a'

void check(int cnt, int start) {
	if (cnt == K) {
		for (int i = 0; i < 27; i++) {
			checked[i] = false;
		}

		// a n t i c
		checked['a' - 'a'] = true;
		checked['n' - 'a'] = true;
		checked['t' - 'a'] = true;
		checked['i' - 'a'] = true;
		checked['c' - 'a'] = true;

		for (int i = 0; i < K; i++) {
			if (!checked[selected[i]]) checked[selected[i]] = true;
		}

		int fail = 0;
		for (int i = 0; i < N; i++) {
			bool pos = true;
			for (int j = 0; j < word[i].length(); j++) {
				if (!checked[word[i][j] - 'a']) {
					pos = false;
					break;
				}
			}
			if (!pos) fail++;
		}

		int temp = N - fail;
		result = max(result, temp);
		return;
	}

	for (int i = start; i < 26; i++) {
		if (i == 'a' - 'a' || i == 'n' - 'a' || i == 't' - 'a' || i == 'i' - 'a' || i == 'c' - 'a') continue;
		selected[cnt] = i;
		check(cnt + 1, i + 1);
	}
}

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}
	
	K -= 5;
	if (K < 0) cout << 0 << '\n';
	else {
		check(0, 0);
		cout << result << '\n';
	}

}