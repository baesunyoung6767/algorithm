#include <string>
#include <vector>
#include <set>
#include <iostream>
#define MAX 9
using namespace std;

vector<string>user_list[MAX];
set<set<string>> result;

void checkResult(int cnt, set<string> temp) {
    if(cnt >= 0) {
        for(int i = 0; i<user_list[cnt].size(); i++) {
            if(temp.find(user_list[cnt][i]) == temp.end()) {
                temp.insert(user_list[cnt][i]);
                checkResult(cnt-1, temp);
                temp.erase(user_list[cnt][i]);
            }
        }
    } else {
        // 하나의 경우의 수 완성
        result.insert(temp);
    }
}

bool isPos(string user, string banned) {
    for(int i = 0; i<user.size(); i++) {
        if(user[i] != banned[i] && banned[i] != '*') return false;
    }    
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    // banned_id에 가능한 user_id 찾기
    for(int i = 0; i<banned_id.size(); i++) {
        for(int j = 0; j<user_id.size(); j++) {
            if(banned_id[i].size() != user_id[j].size()) continue;
            if(isPos(user_id[j], banned_id[i])) {
                user_list[i].push_back(user_id[j]);
            }
        }
    }
    
    set<string> s;
    checkResult(banned_id.size()-1, s);
    answer = result.size();
    return answer;
}