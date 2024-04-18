#include <string>
#include <vector>
#include <set>
using namespace std;
string target;
int visited[7] = {0};
set<int> check;

void find(string result) {
    // 소수 판별
    bool isPos = true;
    
    if(result.length() > 0) {
        int num = stoi(result);
        if(num != 0 && num != 1) {
            for(int i = 2; i<num; i++) {
                if(num % i == 0) {
                    isPos = false;
                    break;
                }
            }
            if(isPos) check.insert(num);
        }
    }
    
    for(int i = 0; i<target.length(); i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            find(result+target[i]);
            visited[i] = 0;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    target = numbers;
    find("");
    answer = check.size();
    return answer;
}