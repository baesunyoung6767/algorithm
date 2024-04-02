#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<int> v;
stack<int> s;
int cnt = 0;

int main() {
	cin >> N;

	int x, y; 
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(y);
	}
	v.push_back(0);

	for (int i = 0; i < v.size(); i++) {
		while (!s.empty() && s.top() > v[i]) {
			cnt++;
			s.pop();
		}
		if (!s.empty() && s.top() == v[i]) s.pop();
		s.push(v[i]);
	}
	cout << cnt << '\n';
}