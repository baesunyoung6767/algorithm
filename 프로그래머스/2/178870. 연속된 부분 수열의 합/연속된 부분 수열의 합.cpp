#include <string>
#include <vector>

using namespace std;

int minLen = 987654321;
int minIdx = 987654321;
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int start = 0;
    int end = 0;
    int sum = sequence[start];
    
    while(start <= end && end <= sequence.size() - 1) {
        
        if(sum < k) {
            end += 1;
            sum += sequence[end];
        } else if(sum == k) {
            // 길이가 더 짧은 거
            if(end - start + 1 < minLen) {
                minLen = end - start + 1;
                minIdx = start;
                answer = {start, end};
            }
            // 시작 인덱스가 작은 거
            else if(end - start + 1 == minLen && start < minIdx) {
                minIdx = start;
                answer = {start, end};
            }
            sum -= sequence[start];
            start += 1;
        }
       else {
            sum -= sequence[start];
            start += 1;
       }
    }
    
    
    return answer;
}