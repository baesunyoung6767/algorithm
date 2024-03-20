#include <iostream>
#include <vector>
#include <queue>
#define MAX 3001
using namespace std;

int N;
vector<int> v[MAX];
int cycle[MAX] = { 0 };
int visited[MAX] = { 0 };
int beforeNode[MAX] = { 0 };
bool isCycle = false;
int result[MAX] = { 0 };
// 역과 순환선 거리 계산

void output() {
	queue<pair<int, int>> q;

	for (int i = 1; i <= N; i++) {
		if (cycle[i] == 1) {
			q.push({ i, 0 });
			result[i] = 0;
			visited[i] = 1;
		}
	}

	while (!q.empty()) {
		int curNode = q.front().first;
		int curCnt = q.front().second;
		q.pop();

		for (int i = 0; i < v[curNode].size(); i++) {
			int nextNode = v[curNode][i];
			if (visited[nextNode] == 1) continue;

			q.push({ nextNode, curCnt + 1 });
			result[nextNode] = curCnt + 1;
			visited[nextNode] = 1;
		}
	}
	
}

// 사이클 확인
// 방문 여부랑 이전 방문 노드 확인해야 함 
// 방문했다 && 이전 방문 노드가 아니다 == 사이클 발생
void checkCycle(int start) {
	visited[start] = 1;
	
	for (int i = 0; i < v[start].size(); i++) {
		int nextNode = v[start][i];
		if (isCycle) break;
		if (visited[nextNode] == 1) {
			// 이전 방문 노드랑 비교
			if (beforeNode[start] == nextNode) continue;
			else {
				// 사이클 발생 -> 역추적해서 노드들 저장
				isCycle = true;
				cycle[start] = 1;
				while (start != nextNode) {
					cycle[beforeNode[start]] = 1;
					start = beforeNode[start];
				}
				return;
			}
		}
		else {
			beforeNode[nextNode] = start;
			checkCycle(nextNode);
		}
	}
}

int main() {
	cin >> N;
	
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	checkCycle(1);
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
	output();
	for (int i = 1; i <= N; i++) {
		cout << result[i] << ' ';
	}
	cout << '\n';
}