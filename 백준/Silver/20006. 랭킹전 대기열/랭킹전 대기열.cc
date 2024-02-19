#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 301

using namespace std;

int p, m; // 플레이어 수, 방의 정원
vector<pair<int, string>> player;
vector<pair<string, int>> room[MAX]; // 각 방에 들어온 플레이어 정보
int roomCnt = 0;

int main() {
	cin >> p >> m;
	
	int a;
	string b;
	for (int i = 0; i < p; i++) {
		cin >> a >> b;
		player.push_back({ a, b });
	}

	for (int i = 0; i < p; i++) {
		if (roomCnt == 0) {
			// 방 생성
			room[0].push_back({ player[i].second, player[i].first });
			roomCnt++;
		}
		else {
			bool check = false;
			for (int j = 0; j < roomCnt; j++) {
				// j번째 방의 정원이 다 찼으면 player i는 j번의 방에 들어갈 수 없음
				if (room[j].size() < m && room[j].front().second - 10 <= player[i].first && room[j].front().second + 10 >= player[i].first) {
					room[j].push_back({ player[i].second, player[i].first });
					check = true;
					break;
				}
			}
			if (!check) {
				room[roomCnt].push_back({ player[i].second, player[i].first });
				roomCnt++;
			}
		}
	}

	for (int i = 0; i < roomCnt; i++) {
		sort(room[i].begin(), room[i].end());
	}

	for (int i = 0; i < roomCnt; i++) {
		if (room[i].size() == m) cout << "Started!\n";
		else cout << "Waiting!\n";
		for (int j = 0; j < room[i].size(); j++) {
			cout << room[i][j].second << " " << room[i][j].first << '\n';
		}
	}
}