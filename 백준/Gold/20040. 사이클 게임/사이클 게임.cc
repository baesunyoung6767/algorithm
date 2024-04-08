#include <iostream>
#include <vector>
#define MAX 500001
using namespace std;

vector<int> v[MAX];
int parent[MAX] = { 0 };
int N, M;

int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) parent[i] = i;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		//v[a].push_back(b);
		//v[b].push_back(a);

		int pa = find(a);
		int pb = find(b);

		if (pa != pb) {
			if (pa < pb) parent[pb] = pa;
			else parent[pa] = pb;
		}
		else {
			cout << i + 1 << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';

}