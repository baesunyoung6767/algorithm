#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

#define MAX 1001
using namespace std;

map<string, int> target; // 유저별 신고당한 횟수
vector<string> mailList;
//map<string, vector<string>> reportList; // 각 유저별 누구 신고했는지 저장
vector<vector<string>> reportList(MAX);
map<string, int> temp; // 중복 신고 제거

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    for(int i = 0; i<report.size(); i++) {
        temp[report[i]]++;
        if(temp[report[i]] == 1) {
            stringstream ss(report[i]);
        string toUser, fromUser;
        
        ss >> fromUser >> toUser;
        
        int idx = 0;
        for(int j = 0; j<id_list.size(); j++) {
            if(id_list[j] == fromUser) {
                idx = j;
                break;
            }
        }
        reportList[idx].push_back(toUser);
        target[toUser]++;
        }
    }
    
    for(int i = 0; i<id_list.size(); i++) {
        string user = id_list[i];
        if(target[user] >= k) { // 신고당한 횟수가 k번 이상이면 메일 리스트 대상
            mailList.push_back(user);
        }
    }
    
    for(int i = 0; i<id_list.size(); i++) {
       int getMail = 0; // i번째 사람이 메일을 받는 횟수
        for(int j = 0; j < reportList[i].size(); j++) {
           if(find(mailList.begin(), mailList.end(), reportList[i][j]) == end(mailList)) continue;
            else getMail++;
       }
        answer.push_back(getMail);
    }
    return answer;
}