#include <string>
#include <vector>

using namespace std;

int result = 0;

void dfs(vector<int> numbers, int sum, int depth, int target) {
    
    if(depth == numbers.size()) {
        if(sum == target) result++;
        return;
    }
    
    dfs(numbers, sum + numbers[depth], depth + 1, target);
    dfs(numbers, sum - numbers[depth], depth + 1, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, 0, 0, target);
    answer = result;
    return answer;
}