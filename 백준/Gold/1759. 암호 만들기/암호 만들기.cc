#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char arr[101];
int selected[101];

void check(int cnt, int start) {
	if (cnt == L) {
		int con = 0, vo = 0;
		string pass = "";
		for (int i = 0; i < L; i++) pass += arr[selected[i]];

		for (int i = 0; i < pass.length(); i++) {
			if (pass[i] == 'a' || pass[i] == 'e' || pass[i] == 'i' || pass[i] == 'o' || pass[i] == 'u') vo++;
			else con++;
		}

		if (vo >= 1 && con >= 2) cout << pass << '\n';
		return;
	}

	for (int i = start; i < C; i++) {
		selected[cnt] = i;
		check(cnt + 1, i + 1);
	}
}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> arr[i];
	sort(arr, arr + C);
	check(0, 0);
	return 0;
}