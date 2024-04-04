#include <string>
#include <vector>
#define MAX 200001
using namespace std;

vector<int> v[MAX];
int visited[MAX] = {0};
int temp[MAX] = {0}; // 먼저 방문해야 하는 방이 있는데 아직 방문을 안했다면
int before[MAX] = {0};

void check(int node) {
    
   // 이미 방문했으면 종료
    if(visited[node] == 1) return;
    
    // 현재 node 전에 방문해야 하는 노드 있는지 체크
    // 방문해야 하는 노드가 있는데 방문을 안했으면 임시 저장
    if(visited[before[node]] == 0) {
        temp[before[node]] = node;
        return;
    }
    // 방문해야 하는 노드 방문했으면
    visited[node] = 1;
    check(temp[node]);
    
    for(int i = 0; i<v[node].size(); i++) check(v[node][i]);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    //bool answer = true;
    
    for(auto& it : path) {
        int a = it[0];
        int b = it[1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(auto& it : order) {
        int a = it[0];
        int b = it[1];
        before[b] = a; // b 방문 전에 a 방문
    }
    
    if(before[0] != 0) return false;
    
    // 0번부터 방문
    visited[0] = 1;
    for(int i = 0; i<v[0].size(); i++) {
        check(v[0][i]); // 0이랑 연결된 노드들 탐색
    }
    
    for(int i = 0; i<n; i++) {
        if(visited[i] == 0) return false;
    }
    return true;
}