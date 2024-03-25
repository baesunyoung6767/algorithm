#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

int n,m,cnt;
vector<int> v[204];
bool vst[204];

void dfs(int k){
	vst[k] = 1;
	for(int e: v[k]){
		if(!vst[e]){
			dfs(e);
		}
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int x;
			cin >> x;
			if(x == 1) {
				v[i].push_back(j);
			}
		}
	}
	
	
	for(int i=0; i < m; i++){
		int x;
		cin >> x;
		if(!vst[x]){
			cnt++;
			dfs(x);
		}
	}
	
	if(cnt == 1) cout << "YES";
	else cout << "NO";
	return 0;
}