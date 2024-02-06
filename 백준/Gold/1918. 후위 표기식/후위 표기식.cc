#include <iostream>
#include <stack>
using namespace std;

int main() {
	string input;
	cin >> input;

	stack<char> s;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') cout << input[i];
		else if (input[i] == '(') s.push(input[i]);
		else if (input[i] == '*' || input[i] == '/') {
			while (!s.empty() && input[i] != '(' && (s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(input[i]);
		}
		else if (input[i] == '+' || input[i] == '-') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.push(input[i]);
		}
		else if (input[i] == ')') {
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}

	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

}
