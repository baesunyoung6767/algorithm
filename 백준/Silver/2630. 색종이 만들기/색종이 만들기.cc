#include <iostream>
#define MAX 128
using namespace std;

// 1 2 
// 3 4
int N;
int arr[MAX][MAX] = { 0 };
int blue = 0, white = 0; // 1, 0
void check(int n, int y, int x) {
	bool isDiv = false;

	for (int i = y; i < n + y; i++) {
		for (int j = x; j < n + x; j++) {
			if (arr[i][j] != arr[y][x]) {
				isDiv = true;
				check(n / 2, y, x);
				check(n / 2, y, x + n / 2);
				check(n / 2, y + n / 2, x);
				check(n / 2, y + n / 2, x + n / 2);
				break;
			}
		}
		if (isDiv) break;
	}
	if (!isDiv) {
		if (arr[y][x] == 1) blue++;
		else white++;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	check(N, 0, 0);
	cout << white << '\n' << blue << '\n';
}
