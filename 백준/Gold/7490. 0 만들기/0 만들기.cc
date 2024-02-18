#include <iostream>
#include <queue>
#include <deque>
#define MAX 101
using namespace std;

int T, N;
char num[MAX] = { 0 };
//char math[MAX];
char symbol[] = { '+', '-', ' ' };
queue<char> math;
deque<int> temp;
priority_queue<string, vector<string>, greater<string>> output;



void check(int depth, string result) {
	result = result + char(num[depth]);

	if (result.length() == N + (N-1)) {
		for (int i = 0; i < result.length(); i++) {
			if (result[i] >= '1' && result[i] <= '9') {
				// 숫자 따로 저장
				temp.push_back(result[i] - '0'); 
			}
			else if(result[i] == '+' || result[i] == '-'){
				math.push(result[i]);
			}
			else { // 공백인 경우
				int a = temp.back(); temp.pop_back();
				temp.push_back(a * 10 + (result[++i] - '0'));
			}
		}

		int sum = temp.front(); temp.pop_front();

		while (!temp.empty()) {
			if (math.front() == '+') {
				sum += temp.front();
				temp.pop_front();
				math.pop();
			}
			else if (math.front() == '-') {
				sum -= temp.front();
				temp.pop_front();
				math.pop();
			}
		}

		if (sum == 0) {
			output.push(result);
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		check(depth + 1, result + symbol[i]);
	}
}

int main() {
	cin >> T;

	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) num[i] = (i+1) + '0';
		check(0, "");
		while (!output.empty()) {
			cout << output.top() << '\n';
			output.pop();
		}
		cout << '\n';
	}

}