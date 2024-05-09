#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    // for(int i = 0; i<works.size(); i++) {
    //     pq.push(works[i]);
    // }
    priority_queue<int> pq(works.begin(), works.end()); // works 값 넣기
    
    for(int i = 0; i<n; i++) {
        if(pq.top() > 0) {
            int maxNum = pq.top(); pq.pop();
            maxNum--;
            pq.push(maxNum);
        } 
    }
    
    while(!pq.empty()) {
        answer += pow((long long)pq.top(),2);
        pq.pop();
    }
    
    return answer;
}