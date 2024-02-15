#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int arr[101][101] = { 0 };
int result[101][101] = { 0 };
bool possible = false;

void worldcup(int depth) {
	if (depth == v.size()) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] != result[i][j]) return;
			}
		}

		possible = true;
		return;
	}


	int a = v[depth].first; 
	int b = v[depth].second;

	arr[a][0]++;
	arr[b][2]++;
	worldcup(depth + 1);
	arr[a][0]--;
	arr[b][2]--;

	arr[a][1]++;
	arr[b][1]++;
	worldcup(depth + 1);
	arr[a][1]--;
	arr[b][1]--;

	arr[a][2]++;
	arr[b][0]++;
	worldcup(depth + 1);
	arr[a][2]--;
	arr[b][0]--;
	return;
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			v.push_back({ i, j });
		}
	}

	int cnt = 0;
	while (cnt < 4) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				arr[i][j] = 0;
				cin >> result[i][j];
			}
		}
		worldcup(0);

		if (possible) cout << 1 << ' ';
		else cout << 0 << ' ';
		possible = false;
		cnt++;
	}
}