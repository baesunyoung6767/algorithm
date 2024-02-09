#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#define MAX 1000001
using namespace std;

// 반례
// 16
// -60 - 41 - 100 8 - 8 - 52 - 62 - 61 - 76 - 52 - 52 14 - 11 - 2 - 54 46
int main() {
	int N;
	int checkLen[MAX] = { 0 };
	int input[MAX] = { 0 };

	vector<int> v;
	stack<int> s;
	cin >> N;

	int num, idx = 0;
	cin >> num;
	v.push_back(num);
	checkLen[0] = ++idx;
	input[0] = num;

	for (int i = 1; i < N; i++) {
		cin >> num;
		input[i] = num;

		if (v.back() < num) {
			v.push_back(num);
			checkLen[i] = ++idx;
		}
		else {
			*lower_bound(v.begin(), v.end(), num) = num;
			checkLen[i] = lower_bound(v.begin(), v.end(), num) - v.begin() + 1;
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		if (checkLen[i] == idx) {
			s.push(input[i]);
			idx--;
		}
	}

	cout << s.size() << '\n';
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
}