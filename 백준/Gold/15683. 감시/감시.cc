#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 101
using namespace std;

vector<pair<int, int>> v;
int x[] = { 1, 0, -1, 0 };
int y[] = { 0, -1, 0, 1 };
int map[MAX][MAX] = { 0 };
int output = 987654321;
int N, M;

void check(int cy, int cx, int d) {
    d %= 4;
    while (1) {
        int ny = cy + y[d];
        int nx = cx + x[d];
        cy = ny; cx = nx;
        if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == 6) break;
        if (map[ny][nx] != 0) continue;
        map[ny][nx] = -1;
    }
}

void dfs(int cnt) {
    if (cnt == v.size()) { // 모든 cctv에 대한 탐색 끝
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) count++;
            }
        }

        output = min(output, count);
        return;
    }

    int cy = v[cnt].first;
    int cx = v[cnt].second;
    int dir = map[cy][cx];
    int temp[MAX][MAX] = { 0 };
    for (int d = 0; d < 4; d++) { // 우 상 좌 하
        // 배열 임의 저장

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                temp[i][j] = map[i][j];
            }
        }

        switch (dir) {
        case 1:
            check(cy, cx, d);
            break;
        case 2:
            check(cy, cx, d);
            check(cy, cx, d + 2);
            break;
        case 3:
            check(cy, cx, d);
            check(cy, cx, d + 1);
            break;
        case 4:
            check(cy, cx, d);
            check(cy, cx, d + 1);
            check(cy, cx, d + 2);
            break;
        case 5:
            check(cy, cx, d);
            check(cy, cx, d + 1);
            check(cy, cx, d + 2);
            check(cy, cx, d + 3);
            break;
        default:
            break;
        }

        dfs(cnt + 1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] = temp[i][j];
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5) {
                v.push_back({ i, j });
            }
        }
    }

    dfs(0);
    cout << output << '\n';
}

