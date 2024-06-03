#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string S, T;
	cin >> S >> T;

	// 두 문자열 길이 비교
	while (1) {
		if (S.length() == T.length()) {
			if (S == T) cout << 1 << '\n';
			else cout << 0 << '\n';
			break;
		}
		else {
			// 뒤에서부터
			// A인 경우 A 삭제, B인 경우 B 삭제 하고 뒤집기
			if(T[T.length()-1] == 'A') T = T.substr(0, T.length() - 1);
			else if (T[T.length() - 1] == 'B') {
				T = T.substr(0, T.length() - 1);
				reverse(T.begin(), T.end());
			}
		}
	}
}