#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<vector<int>> userIdList;
set<set<int>> result;

bool comIsPos(string a, string b) { // 아이디, 불량 사용자
    for(int i = 0; i<a.size(); i++) {
        if(a[i] != b[i] && b[i] != '*') return false;
    }    
    return true;
} 

void calcResult(int cnt, set<int> data) {
    if(cnt >=0) {
        for(int i = 0; i < userIdList[cnt].size(); i++) {
            if(data.find(userIdList[cnt][i]) == data.end()) {
                data.insert(userIdList[cnt][i]);
                calcResult(cnt-1, data);
                data.erase(userIdList[cnt][i]);
            }
        }
    } else {
        result.insert(data);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    userIdList = vector<vector<int>> (banned_id.size());
    for(int i = 0; i<banned_id.size(); i++) {
        for(int j = 0; j<user_id.size(); j++) {
            if(user_id[j].size() == banned_id[i].size()) {
                if(comIsPos(user_id[j], banned_id[i])) {
                    userIdList[i].push_back(j);
                }
            }
        }
    }
    
    set<int> temp;
    calcResult(banned_id.size() - 1, temp);
    answer = result.size();
    return answer;
}