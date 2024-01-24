#include <iostream>
using namespace std;

int num[1025][1025], acc[1025][1025];

int main() {
	ios::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num[i][j];
			acc[i][j] = acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1] + num[i][j];
		}
	}

	int x1, y1, x2, y2, result;

	while (m--) {
		cin >> x1 >> y1 >> x2 >> y2;
		result = acc[x2][y2] - acc[x1 - 1][y2] - acc[x2][y1 - 1] + acc[x1 - 1][y1 - 1];
		cout << result << '\n';
	}
	return 0;
}