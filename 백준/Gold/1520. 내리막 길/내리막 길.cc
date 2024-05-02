#include <iostream>
#include <queue>

#define MAX 501
using namespace std;

int M, N;
int map[MAX][MAX] = { 0 };
int dp[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };

int x[] = { 1, 0, -1, 0 };
int y[] = { 0, 1, 0, -1 };
int result = 0;

int check(int cy, int cx) {

    if (cy == M - 1 && cx == N - 1)  return 1;
    if (visited[cy][cx] == 1) return dp[cy][cx];

    visited[cy][cx] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = cy + y[i];
        int nx = cx + x[i];

        if (ny < 0 || nx < 0 || ny >= M || nx >= N || map[ny][nx] >= map[cy][cx]) continue;
        dp[cy][cx] += check(ny, nx);
    }
    return dp[cy][cx];
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    cout << check(0, 0) << '\n';
}