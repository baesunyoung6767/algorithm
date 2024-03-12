#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N; // 교실 크기
vector<int> like[401];
int school[21][21] = { 0 };
int x[] = { 0, -1, 1, 0 };
int y[] = { -1, 0, 0, 1 };


void tempCheck() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << school[i][j] << ' ';
		}
		cout << '\n';
	}
}

// 최종 출력
void output() {
	int total = 0;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int temp = school[i][j]; // 현재 위치의 학생 번호
			int likeCnt = 0; // 좋아하는 학생의 수
			for (int k = 0; k < 4; ++k) {
				int nx = j + x[k];
				int ny = i + y[k];
				if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
				if (find(like[temp].begin(), like[temp].end(), school[ny][nx]) != like[temp].end()) likeCnt++;
			}
			// 만족도 계산
			if (likeCnt == 0) total += 0;
			else if (likeCnt == 1) total += 1;
			else if (likeCnt == 2) total += 10;
			else if (likeCnt == 3) total += 100;
			else if (likeCnt == 4) total += 1000;
		}
	}
	cout << total << '\n';
}

// 자리 배치 탐색
void check(int target) {
	// 인접한 곳에 좋아하는 학생 수, 빈칸 수, 최종적으로 배치할 위치
	int maxLike = -1, maxEmpty = -1, fY = -1, fX = -1; 

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int likeStudent = 0, emptyPlace = 0;

			if (school[i][j] != 0) continue;
			
			for (int k = 0; k < 4; k++) {
				int ny = i + x[k];
				int nx = j + y[k];

				if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;

				if (school[ny][nx] == 0) emptyPlace++;
				
				// 좋아하는 학생이 있는지 체크
				for (int l = 0; l < 4; l++) {
					if (like[target][l] == school[ny][nx]) likeStudent++;
				}
			}

			if (likeStudent > maxLike) {
				maxLike = likeStudent;
				maxEmpty = emptyPlace;
				fY = i;
				fX = j;
			}
			else if (likeStudent == maxLike) {
				if (maxEmpty < emptyPlace) {
					maxEmpty = emptyPlace;
					fY = i;
					fX = j;
				}
				else if (maxEmpty == emptyPlace) {
					// 행이 더 작아야 함
					if (fY == i && fX > j) fX = j;
					else if (fY > i) {
						fY = i;
						fX = j;
					}
				}
			}
		}
	}
	school[fY][fX] = target;
}

int main() {
	cin >> N;

	int a, b;
	for (int i = 0; i < N * N; i++) {
		cin >> a;
		for (int j = 0; j < 4; j++) {
			cin >> b;
			like[a].push_back(b);
		}
		check(a);
	}
	//tempCheck();
	output();
}