#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v[201];
int visited[201] = { 0 };

void dfs(int node) {
	for (int i = 0; i < v[node].size(); i++) {
		if (visited[v[node][i]] == 1) continue;
		visited[v[node][i]] = 1;
		dfs(v[node][i]);
	}
}

int main() {
	cin >> N >> M;
	int temp;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			if (temp == 1) v[i].push_back(j);
		}
	}
    
    int cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (visited[temp] == 0) {
            visited[temp] = 1;
			cnt++;
            dfs(temp);
		}
	}

	if(cnt == 1) cout <<"YES\n";
    else cout <<"NO\n";

}
