#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 이미 방문했는데 시작 노드가 아니라면 사이클 x
set<int> s;
int N;
int arr[101] = { 0 };
int visited[101] = { 0 };
vector<int> v;

void init() {
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
}

void check(int startNode, int node) {
	if (visited[node] == 1) {
		if (startNode == node) {
			for (int i = 0; i < v.size(); i++) {
				s.insert(v[i]);
			}
			v.clear();
			return;
		}
		else {
			v.clear();
			return;
		}
	}
	else {
		visited[node] = 1;
		v.push_back(node);
		check(startNode, arr[node]);
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		visited[i] = 1;
		v.push_back(i);
		check(i, arr[i]);
		init();
	}

	cout << s.size() << '\n';
	set<int>::iterator iter = s.begin();
	for (iter; iter != s.end(); iter++) {
		cout << *iter << '\n';
	}
}