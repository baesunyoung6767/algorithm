#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;

int H, W;
int map[MAX] = { 0 };
int result = 0;

int main() {
	cin >> H >> W;
	
	for (int i = 0; i < W; i++) cin >> map[i];

	
	for (int i = 1; i < W - 1; i++) {
		int left_max = -1;
		int right_max = -1;

		// 각 위치에서 왼쪽, 오른쪽 젤 큰 값 구한다
		for (int l = 0; l < i; l++) left_max = max(left_max, map[l]);
		for (int r = W - 1; r > i; r--) right_max = max(right_max, map[r]);

		// 왼쪽 최대, 오른쪽 최대 중 작은 값 구한다
		int water_height = min(left_max, right_max);

		if(water_height > map[i]) result += water_height - map[i];
	}

	cout << result << '\n';
}