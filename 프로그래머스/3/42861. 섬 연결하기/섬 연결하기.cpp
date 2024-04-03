#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101] = {0};
bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2]; // 비용을 기준으로 오름차순
}

int find(int node) {
    if(parent[node] == node) return node;
    return parent[node] = find(parent[node]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i = 0; i<n; i++) parent[i] = i;    
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i = 0; i<costs.size(); i++) {
        // 부모가 다르면 연결
        int a = find(costs[i][0]);
        int b = find(costs[i][1]);
        int cost = costs[i][2];
        
        if(a != b) {
            answer+=cost;
            parent[b] = a;
        }
    }
    
    return answer;
}