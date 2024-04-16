#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for(int i = 0; i<sizes.size(); i++) {
        if(sizes[i][0] < sizes[i][1]) {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }
    
    int maxW = -1;
    int maxH = -1;
    
    for(int i = 0; i<sizes.size(); i++) {
        // 가로 최대
        maxW = max(maxW, sizes[i][0]);    
        // 세로 최대
        maxH = max(maxH, sizes[i][1]);
    }
    
    answer = maxW * maxH;
    return answer;
}