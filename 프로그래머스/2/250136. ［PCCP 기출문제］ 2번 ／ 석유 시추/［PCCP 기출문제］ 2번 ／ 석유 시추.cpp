#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#define MAX 501
using namespace std;

int N, M;
int x[] = {1, 0, -1, 0};
int y[] = {0, 1, 0, -1};
int visited[MAX][MAX] = {0};
vector<vector<int>> map;
int result = -1;
int total[250001] = {0};

void bfs(int startY, int startX, int num) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({startY, startX});
    visited[startY][startX] = 1;
    map[startY][startX] = num;
    
    while(!q.empty()) {
        cnt++;
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        for(int i = 0; i<4; i++) {
            int ny = cy + y[i];
            int nx = cx + x[i];
            
            if(ny < 0 || nx < 0 || ny>=N || nx >= M || visited[ny][nx] == 1 || map[ny][nx] == 0) continue;
            visited[ny][nx] = 1;
            map[ny][nx] = num;
            q.push({ny, nx});
        }
    }
    total[num] = cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int num = 1;
    N = land.size();
    M = land[0].size();
    map = land;
    
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) {
            if(map[i][j] > 0 && visited[i][j] == 0) {
                bfs(i, j, num);
                num++;
            }
        }
    }
    
    for(int i = 0; i<M; i++) {
        int sum = 0;
        set<int> s;
        for(int j = 0; j<N; j++) {
            if(map[j][i] > 0) s.insert(map[j][i]);
        }
        for(auto temp : s) sum += total[temp];
        result = max(sum, result);
    }
    answer = result;
    return answer;
}