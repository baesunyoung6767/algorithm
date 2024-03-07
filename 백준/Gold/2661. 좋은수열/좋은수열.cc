#include <iostream>
#include <string>
using namespace std;

int N;
bool pos = false;

void check(int cnt, string tempStr) {
	// 불가능하면 바로 리턴
	for (int i = 0; i < tempStr.length(); i++) {
		string temp1 = tempStr.substr(i, (tempStr.length() - i) / 2);
		string temp2 = tempStr.substr(i + (tempStr.length() - i) / 2, tempStr.length());
		if (temp1.compare(temp2) == 0) return;
	}

	if (cnt == N) {
		cout << tempStr << '\n';
		pos = true;
		return;
	}

	if (pos) return;
	check(cnt + 1, tempStr + '1');
	if (pos) return;
	check(cnt + 1, tempStr + '2');
	if (pos) return;
	check(cnt + 1, tempStr + '3');
}
int main() {
	cin >> N;

	check(0, "");
}