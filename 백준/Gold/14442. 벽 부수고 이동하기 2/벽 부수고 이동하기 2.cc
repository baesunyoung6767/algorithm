#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 1001
using namespace std;

// 벽을 k개 까지 부수고 이동 가능
int N, M, K;
int arr[MAX][MAX] = { 0 };
int visited[MAX][MAX][11] = { 0 };
int x[] = { 1, 0, -1, 0 };
int y[] = { 0, -1, 0, 1 };

int bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q; // 행,열, 이동 거리, 지나온 벽 개수 (k개 넘으면 안됨)
    q.push({ {0, 0}, {1, 0} });
    visited[0][0][0] = 1;

    while (!q.empty()) {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int dis = q.front().second.first;
        int wCheck = q.front().second.second;
        q.pop();

        if (cy == N - 1 && cx == M - 1) {
            return dis;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cy + y[i];
            int nx = cx + x[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

            if (arr[ny][nx] == 1 && wCheck < K && visited[ny][nx][wCheck - 1] == 0) {
                q.push({ {ny, nx}, {dis + 1, wCheck + 1} });
                visited[ny][nx][wCheck + 1] = 1;
            }
            if (arr[ny][nx] == 0 && visited[ny][nx][wCheck] == 0) {
                q.push({ {ny, nx}, {dis + 1, wCheck } });
                visited[ny][nx][wCheck] = 1;
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> M >> K;

    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            arr[i][j] = tmp[j] - '0';
        }
    }
    
    cout << bfs() << "\n";
}