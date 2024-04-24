#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mineralsInt;
int result = 987654321;
int power[3][3] = {{1, 1, 1}, 
                   {5, 1, 1}, 
                   {25, 5, 1}};

void check(vector<int> picks, int idx, int sum) { 
    if(result <= sum) return;
    
    if((picks[0] == 0 && picks[1] == 0 && picks[2] == 0) || idx >= mineralsInt.size()) {
        // 최소값 구하기
        result = min(result, sum);
        return;
    }
    
    int curSum[3] = {0};
    int nextIdx = 0;
    for(int i = idx; i<idx+5; i++) {
        if(i >= mineralsInt.size()) {
            nextIdx = i;
            break;
        }  
        curSum[0] += power[0][mineralsInt[i]];
        curSum[1] += power[1][mineralsInt[i]];
        curSum[2] += power[2][mineralsInt[i]];
        nextIdx = i;
    }
   
    
    for(int i = 0; i<3; i++) {
        if(picks[i] != 0) {
            picks[i]--;
            check(picks, nextIdx + 1, sum + curSum[i]);
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    for(int i = 0; i<minerals.size(); i++) {
        if(minerals[i] == "diamond") mineralsInt.push_back(0);
        else if(minerals[i] == "iron") mineralsInt.push_back(1);
        else if(minerals[i] == "stone")mineralsInt.push_back(2);
    }
    
    check(picks, 0, 0);
    answer = result;
    return answer;
}