#include <iostream>
#include <queue>
#include <stack>
#define MAX 200001
using namespace std;

int N, K;
int memory[MAX] = { 0 };
int visited[MAX] = { 0 };

void check() {
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = 1;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == K) {
			// 어떻게 이동해야 하는지 데이터 출력
			cout << cnt << '\n';
			stack<int> s;
			s.push(K);
			int idx = K;
			while(idx != N) {
				s.push(memory[idx]);
				idx = memory[idx];
			}

			while (!s.empty()) {
				cout << s.top() << ' ';
				s.pop();
			}
			break;
		}

		int a = cur + 1;
		if (a >= 0 && a <= 200000 && visited[a] == 0) {
			memory[a] = cur;
			visited[a] = 1;
			q.push({ a, cnt + 1 });
		}
		int b = cur - 1;
		if (b >= 0 && b <= 200000 && visited[b] == 0) {
			memory[b] = cur;
			visited[b] = 1;
			q.push({ b, cnt + 1 });
		}
		int c = cur * 2;
		if (c >= 0 && c <= 200000 && visited[c] == 0) {
			memory[c] = cur;
			visited[c] = 1;
			q.push({ c, cnt + 1 });
		}
	}
}

int main() {
	cin >> N >> K;

	check();
}