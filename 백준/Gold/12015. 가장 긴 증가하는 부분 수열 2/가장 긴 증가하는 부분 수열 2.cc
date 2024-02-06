#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, tmp;
	cin >> n;
	vector<int> v;

	while(n--) {
		cin >> tmp;
		if (v.empty() || v.back() < tmp) {
			v.push_back(tmp);
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), tmp);
			*it = tmp;
		}
	}

	cout << v.size() << '\n';

}