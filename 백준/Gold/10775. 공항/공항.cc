#include <iostream>
#define MAX 100001
using namespace std;

int G, P;
int g[MAX] = { 0 };
int parent[MAX] = { 0 };
int result = 0;

int find(int node) {
	if (parent[node] == node) return node;
	else return parent[node] = find(parent[node]);
}

void unionFuc(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> G >> P;
	
	for (int i = 0; i < P; i++) cin >> g[i];
	for (int i = 0; i <= G; i++) parent[i] = i;
	
	int num;
	for (int i = 0; i < P; i++) {
		num = find(g[i]);
		if (num == 0) break;
		result++;
		unionFuc(num, num - 1);
	}

	cout << result << '\n';
}