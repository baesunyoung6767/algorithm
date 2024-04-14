#include <iostream>
#define MAX 100001
using namespace std;

int N, M;
int parent[MAX] = { 0 };
int cnt = 0;

int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) parent[i] = i;

	int a, b;
	for(int i = 0; i<M; i++) {
		cin >> a >> b;

		a = find(a);
		b = find(b);

		if (a != b) {
			if (a < b) parent[b] = a;
			else parent[a] = b;
		}
		else cnt++;
	}

	/*for (int i = 1; i <= N; i++) cout << parent[i] << ' ';
	cout << '\n';*/

	for (int i = 1; i <= N; i++) {
		if (i == find(i)) cnt++;
	}

	cout << cnt - 1 << '\n';
}