#include <iostream>
#include <vector>
#define MAX 200001
using namespace std;

int V, E;
int visited[MAX] = { 0 };

int status[MAX] = { 0 };
vector<int> v[MAX];

bool result = true;

void init() {
	for (int i = 1; i <= V; i++) {
		visited[i] = 0;
		status[i] = 0;
		v[i].clear();
	}
	result = true;
}

void check(int node, int status_num) {
	visited[node] = 1;

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (visited[next] == 0) {
			status[next] = status_num * -1;
			check(next, status_num * -1);
		}
		else {
			if (status[next] == status[node]) {
				result = false;
				return;
			}
		}
	}
}


int main() {
	int T; cin >> T;

	while (T--) { 
		cin >> V >> E;

		int a, b;
		for (int i = 0; i < E; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		
		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0) {
				status[i] = 1;
				check(i, 1);
			}
		}

		/*cout << "status 출력 =============\n";
		for (int i = 1; i <= V; i++) {
			cout << status[i] << ' ';
		}*/

		if (result) cout << "YES\n";
		else cout << "NO\n";
		init();
	}
}