#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, pair<int, int>>> v;
int result = 0;
int parents[1001] = { 0 };
int nodeCnt = 0;

void initP() {
	for (int i = 0; i <= N; i++) parents[i] = i;
}

int checkPnode(int num) {
	if (parents[num] == num) return num;
	return parents[num] = checkPnode(parents[num]);
}

void unionNode(int x, int y) {
	int a = checkPnode(x);
	int b = checkPnode(y);
	parents[b] = a;
}

void checkMST() {
	initP();
    result = 0;
	for (int i = 0; i < M+1; i++) {
		int node1 = v[i].second.first;
		int node2 = v[i].second.second;

		if (checkPnode(node1) == checkPnode(node2)) continue;
		nodeCnt++;
		result += v[i].first;
		unionNode(node1, node2);
		if (nodeCnt == N) break;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> N >> M;

	for (int i = 0; i < M+1 ; i++) {
		cin >> A >> B >> C;
		C ^= 1; // 오르막길 : 1, 내리막길 : 0 으로 변경
		v.push_back({ C,{A,B} });
	}

	sort(v.begin(), v.end());
	checkMST();
	int minResult = result * result;

	sort(v.begin(), v.end(), greater<pair<int, pair<int, int>>>());
	checkMST();
	int maxResult = result * result;
	cout << maxResult - minResult << '\n';
}