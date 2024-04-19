#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    vector<int> v = stones;
    vector<int> temp = stones;
    sort(v.begin(), v.end());
    int start = v[0];
    int end = v[v.size()-1];

    while(start<=end) {
        int mid = (start+end)/2;
        
        int jump = 0;
        bool isPos = true;
        temp = stones;
        
        for(int i = 0; i<stones.size(); i++) {
            temp[i] -= mid;
            
            if(temp[i] < 0) jump++;
            else jump = 0;
            
            if(jump == k) {
                isPos = false;
                break;
            }
        }
        
        if(!isPos) end = mid - 1;
        else {
            answer = max(answer, mid);
            start = mid + 1;
        }
    }
    return answer;
}