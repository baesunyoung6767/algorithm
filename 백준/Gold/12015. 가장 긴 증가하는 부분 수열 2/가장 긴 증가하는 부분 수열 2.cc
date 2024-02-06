#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001
using namespace std;

int main() {
	int N;
	int arr[MAX] = { 0 };
	cin >> N;

	vector<int> v;
	int tmp;
	cin >> tmp;
	v.push_back(tmp);
	for (int i = 1; i < N; i++) {
		cin >> tmp;
		if (v.back() < tmp) v.push_back(tmp);
		else {
			*lower_bound(v.begin(), v.end(), tmp) = tmp;
		}
	}

	cout << v.size() << '\n';
}
