#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int N, M;
int C, H, K;
int parent[MAX] = { 0 };
int cnt[MAX] = { 0 };
bool visited[MAX] = { 0 };
priority_queue<int> pq;
int result = 0;

int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		cnt[i] = 1;
	}
	
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		a = find(a);
		b = find(b);

		if (a != b) {
			if (a < b) {
				parent[b] = a;
				cnt[a] += cnt[b];
			}
			else {
				parent[a] = b;
				cnt[b] += cnt[a];
			}
		}
	}

	cin >> C >> H >> K;
	C = find(C);
	H = find(H);
	/*for (int i = 1; i <= N; i++) cout << parent[i] << ' ';
	cout << '\n';*/

	for (int i = 1; i <= N; i++) {
		int node = find(i);
		if (node == C || node == H || visited[node]) continue;
		pq.push(cnt[node]);
		visited[node] = true;
	}

	result += cnt[C];
	while (K--) {
		int current = pq.top();
		pq.pop();
		result += current;
	}

	cout << result << '\n';
}