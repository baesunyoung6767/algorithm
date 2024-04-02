#include <iostream>
#include <queue>

#define MAX 51
using namespace std;

int N, M;
char map[MAX][MAX] = { 0 };
// 0 ~ 5 : a ~ f 열쇠
int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };
int result = 987654321;
int checkKey[6] = { 0 };

void bfs(int startY, int startX, int time) {
    int visited[MAX][MAX] = { 0 };
    queue<pair<pair<int, int>, int>> q;
    q.push({ {startY, startX}, time });
    visited[startY][startX] = 1;

    while (!q.empty()) {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int ctime = q.front().second;
        q.pop();

        if (result != 987654321 && ctime > result) break;

        for (int i = 0; i < 4; i++) {
            int ny = cy + y[i];
            int nx = cx + x[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] == 1) continue;

            if (map[ny][nx] == '1' && ctime + 1 < result) {
                result = ctime + 1;
                return;
            }

            if(map[ny][nx] == '.' || map[ny][nx] == '0')  q.push({ {ny, nx}, ctime + 1 });
            if (map[ny][nx] == 'a' || map[ny][nx] == 'b' || map[ny][nx] == 'c' || map[ny][nx] == 'd' || map[ny][nx] == 'e' || map[ny][nx] == 'f') {
                if (checkKey[map[ny][nx] - 'a'] == 0) {
                    checkKey[map[ny][nx] - 'a'] = 1;
                    bfs(ny, nx, ctime + 1);
                    checkKey[map[ny][nx] - 'a'] = 0;
                }
                else  q.push({ {ny, nx}, ctime + 1 });
            }
            if (map[ny][nx] == 'A' || map[ny][nx] == 'B' || map[ny][nx] == 'C' || map[ny][nx] == 'D' || map[ny][nx] == 'E' || map[ny][nx] == 'F') {
                if (checkKey[map[ny][nx] - 'A'] == 0) continue;
                else  q.push({ {ny, nx}, ctime + 1 });
            }
            visited[ny][nx] = 1;
        }

    }
}

int main() {
    cin >> N >> M;

    int startY = 0, startX = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == '0') {
                startY = i; startX = j;
            }
        }
    }

    bfs(startY, startX, 0);
    if (result == 987654321) cout << -1 << '\n';
    else cout << result << '\n';
}