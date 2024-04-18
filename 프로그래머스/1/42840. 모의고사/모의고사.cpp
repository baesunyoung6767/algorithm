#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cnta = 0, cntb = 0, cntc = 0;
int a[] = {1, 2, 3, 4, 5};
int b[] = {2, 1, 2, 3, 2, 4, 2, 5};
int c[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
vector<int> answer;

void check(vector<int> v) {
    int idxa = 0, idxb = 0, idxc = 0;
    
    for(int i = 0; i<v.size(); i++) {
        if(v[i] == a[idxa]) cnta++;
        if(v[i] == b[idxb]) cntb++;
        if(v[i] == c[idxc]) cntc++;
        
        idxa++; if(idxa == 5) idxa = 0;
        idxb++; if(idxb == 8) idxb = 0;
        idxc++; if(idxc == 10) idxc = 0;
    }
    
    int maxCnt = maxCnt = max(cnta, max(cntb,cntc));
    
    if(maxCnt == cnta) answer.push_back(1);
    if(maxCnt == cntb) answer.push_back(2);
    if(maxCnt == cntc) answer.push_back(3);
}

vector<int> solution(vector<int> answers) {
    check(answers);
    return answer;
}