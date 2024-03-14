#include <iostream>
using namespace std;

// 지도 세로, 지도 가로, 주사위 좌표 x, y, 명령 개수
int N, M, x, y, K;
int map[21][21];
int dice[4][3]; // 주사위에 찍히는 숫자 저장할 배열

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// 동(오) 
void north() {
	int temp = dice[1][0];
	dice[1][0] = dice[1][1];
	dice[1][1] = dice[1][2];
	dice[1][2] = dice[3][1];
	dice[3][1] = temp;
}
// 서(왼)
void south() {
	int temp = dice[1][2];
	dice[1][2] = dice[1][1];
	dice[1][1] = dice[1][0];
	dice[1][0] = dice[3][1];
	dice[3][1] = temp;
}
// 남(하)
void east() {
	int temp = dice[0][1];
	for (int i = 0; i < 3; i++) {
		dice[i][1] = dice[i + 1][1];
	}
	dice[3][1] = temp;
}
// 북(상)
void west() {
	int temp = dice[3][1];
	for (int i = 3; i > 0; i--) {
		dice[i][1] = dice[i - 1][1];
	}
	dice[0][1] = temp;
}

void game() {
	int cx = x;
	int cy = y;
	int kind = 0;
	
	for (int i = 0; i < K; i++) {
		cin >> kind;

		int nx = cx + dx[kind-1];
		int ny = cy + dy[kind-1];

		if (nx < 0 || ny < 0 || ny >= N || nx >= M) continue;

		switch (kind)
		{
		case 1: // 동
			north();
			break;
		case 2: // 서
			south();
			break;
		case 3: // 남
			west();
			break;
		case 4: // 북
			east();
			break;
		}
		
		// 바닥 갱신 dice[1][1]
		// map 이동 위치가 0이라면 주사위 바닥면 -> map으로 복사
		if (map[ny][nx] == 0) map[ny][nx] = dice[1][1];
		else {
			dice[1][1] = map[ny][nx];
			map[ny][nx] = 0;
		}

		cout << dice[3][1] << '\n';
		cy = ny; cx = nx;
	}
}

int main() {
	cin >> N >> M >> y >> x >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> map[i][j];
	}

	// 주사위 이동 함수 호출
	game();
}