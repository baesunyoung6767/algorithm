#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned int n, m, max_num = 0, result = 0, tmp;
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
		max_num = max(tmp, max_num);
	}
	
	unsigned int left = 1, right = max_num, mid = 0;
	while (left<=right) {
		mid = (left + right) / 2;
		unsigned int count = 0;

		for (int i = 0; i < n; i++) {
			count += v[i] / mid;
		}
		if (count >= m) {
			left = mid + 1;
			result = max(result, mid);
		}
		else {
			right = mid - 1;
		}
	}
	cout << result << '\n';
	return 0;
}