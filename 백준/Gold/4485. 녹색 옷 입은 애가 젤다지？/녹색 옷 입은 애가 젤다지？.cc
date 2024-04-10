#include <iostream>
#include <queue>
using namespace std;

int N;
int y[] = { 0, 1, 0, -1 };
int x[] = { 1, 0, -1, 0 };

int main() {
	int t = 1;
	while (1) {
		cin >> N;
		if (N == 0) break;

		int map[126][126] = { 0 };
		int dist[126][126] = { 0 };

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				dist[i][j] = 987654321;
			}
		}

		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		pq.push({ map[0][0], { 0,0 } });
		dist[0][0] = map[0][0];

		while (!pq.empty()) {
			int cy = pq.top().second.first;
			int cx = pq.top().second.second;
			int cost = pq.top().first;
			pq.pop();

			for (int i = 0; i < 4; i++) {
				int ny = cy + y[i];
				int nx = cx + x[i];
				int ncost = map[ny][nx];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				
				if (dist[ny][nx] > dist[cy][cx] + ncost) {
					dist[ny][nx] = dist[cy][cx] + ncost;
					pq.push({ dist[ny][nx], {ny, nx} });
				}
			}
		}

		cout << "Problem " << t << ": " << dist[N - 1][N - 1] << '\n';
		t++;
	}
}