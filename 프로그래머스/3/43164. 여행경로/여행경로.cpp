#include <string>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

vector<vector<string>> v;
int visited[MAX] = {0};
vector<string> answer;
bool isPos = false;

void dfs(string start, int depth) {
    answer.push_back(start);
    
    if(depth == v.size()) {
        isPos = true;
        return;
    }
    
    for(int i = 0; i<v.size(); i++) { // v.size() == 3 
        if(visited[i] == 1) continue;
        if(v[i][0] == start) {
            visited[i] = 1;
            dfs(v[i][1], depth + 1);
            if(!isPos) {
                answer.pop_back();
                visited[i] = 0;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    v = tickets;
    dfs("ICN", 0);
    
    return answer;
}