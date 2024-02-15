#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
int num[10];
int check[10];

void seq(int len) {
	if (len == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	int last = 0;
	for (int i = 0; i < n; i++) {
		if (check[i] == 0 && num[i] != last) {
			arr[len] = num[i];
			last = arr[len];
			check[i] = 1;
			seq(len + 1);
			check[i] = 0;
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	seq(0);
	return 0;
}