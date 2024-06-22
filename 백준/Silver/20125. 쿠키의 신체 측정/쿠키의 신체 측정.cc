#include <iostream>
#define MAX 1001
using namespace std;

char cookie[MAX][MAX];

int N;
int heartX, heartY, arm_left = 0, arm_right = 0, leg_right = 0, leg_left = 0, waist = 0, waistY, waistX;

void find_body() {
	// 팔 찾기
	for (int i = heartX; i >= 0; i--) {
		if (cookie[heartY][i] != '*') break;
		arm_left += 1;
	}

	for (int i = heartX; i < N; i++) {
		if (cookie[heartY][i] != '*') break;
		arm_right += 1;
	}

	waistX = heartX;
	// 허리 찾기
	for (int i = heartY; i < N; i++) {
		if (cookie[i][heartX] != '*') break;
		waist += 1;
		waistY = i;
	}

	// 다리 찾기
	for (int i = waistY + 1; i < N; i++) {
		if (cookie[i][waistX - 1] != '*') break;
		leg_left += 1;
	}

	for (int i = waistY + 1; i < N; i++) {
		if (cookie[i][waistX + 1] != '*') break;
		leg_right += 1;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cookie[i][j];
		}
	}

	bool isBreak = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(cookie[i][j] == '*') {
				heartX = j;
				heartY = i + 1;
				find_body();
				isBreak = true;
				break;
			}
		}
		if (isBreak) break;
	}

	cout << heartY + 1 << ' ' << heartX + 1<< '\n';
	cout << arm_left - 1 << ' ' << arm_right - 1<< ' ' << waist - 1 << ' ' << leg_left << ' ' << leg_right<< '\n';
}