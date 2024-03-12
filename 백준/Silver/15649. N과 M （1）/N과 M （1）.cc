#include <iostream> 
using namespace std; 

bool visited[9];
int arr[9];
int n, m;
void permutation(int cnt);

int main() { 
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	permutation(0);
	return 0;
}

void permutation(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << arr[i] <<' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			permutation(cnt + 1);
			visited[i] = false;
		}
	}
}