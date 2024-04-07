#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#define MAX 11
using namespace std;

int N;
int people[MAX] = { 0 };
int selected[MAX] = { 0 };
int result = 987654321;

vector<int> v[MAX];

bool isConnect(vector<int> temp, int select) {
	int visited[MAX] = { 0 };
	queue<int> q;
	q.push(temp[0]);
	visited[temp[0]] = 1;
	int cnt = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i];
			if (visited[next] == 1 || selected[next] != select) continue;
			cnt++;
			visited[next] = 1;
			q.push(next);
		}
	}

	if (temp.size() - 1 == cnt) return true;
	else return false;
}

// 구역 나누는 경우의 수 구하기
void check(int depth) {
	if (depth == N + 1) {
		vector<int> a;
		vector<int> b;
		for (int i = 1; i <= N; i++) {
			if (selected[i] == 1) a.push_back(i);
			else b.push_back(i);
		}

		if (a.size() == 0 || b.size() == 0) return; // 선거구는 구역을 적어도 하나는 포함
		// 각 구역이 인접한가 
		if (isConnect(a, 1) && isConnect(b, 0)) {
			int sumA = 0, sumB = 0;
			for (int i = 0; i < a.size(); i++) {
				int node = a[i];
				sumA += people[node];
			}

			for (int i = 0; i < b.size(); i++) {
				int node = b[i];
				sumB += people[node];
			}

			result = min(result, abs(sumA - sumB));
		}
		return;
	}

	selected[depth] = 1;
	check(depth + 1);
	selected[depth] = 0;
	check(depth + 1);
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> people[i];
	}

	int cnt, connect;
	for (int i = 1; i <= N; i++) {
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> connect;
			v[i].push_back(connect);
		}
	}

	check(0);
	if (result == 987654321) cout << -1 << '\n';
	else cout << result << '\n';

}