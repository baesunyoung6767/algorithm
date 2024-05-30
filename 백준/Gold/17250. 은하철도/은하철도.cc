#include <iostream>
#define MAX 100001
using namespace std;

int N, M;
int arr[MAX] = { 0 };
int parent[MAX] = { 0 };

int find(int node) {
	if (parent[node] == node) return node;
	else return parent[node] = find(parent[node]);
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		parent[i] = i;
	}

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		int pa = find(a);
		int pb = find(b);

		if (pa != pb) {
			
			if (pa < pb) {
				parent[pb] = pa;
				arr[pa] += arr[pb];
				cout << arr[pa] << '\n';
			}
			else {
				parent[pa] = pb;
				arr[pb] += arr[pa];
				cout << arr[pb] << '\n';
			}
		}
		else {
			cout << arr[pa] << '\n';
		}
	} 
}