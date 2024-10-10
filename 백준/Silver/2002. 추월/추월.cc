#include <iostream>
#include <vector>
#include <map>
#define MAX 1001
using namespace std;

int N;
int result = 0;
map<string, int> m;
vector<int> finish;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	finish.resize(N, 0);

	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		m[temp] = i;
	}

	for (int j = 0; j < N; j++) {
		cin >> temp;
		finish[j] = m[temp];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (finish[i] > finish[j]) {
				result++;
				break;
			}
		}
	}

	cout << result << '\n';
}