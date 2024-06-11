#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string input;
string boom;
stack<char> temp_char;

int main() {
	cin >> input >> boom;

	for (int i = 0; i < input.size(); i++) {
		temp_char.push(input[i]);

		if (input[i] == boom[boom.length() - 1] && temp_char.size() >= boom.size()) {
			string temp;
			for (int j = 0; j < boom.size(); j++) {
				temp += temp_char.top();
				temp_char.pop();
			}
			reverse(temp.begin(), temp.end());

			if (temp != boom) {
				for (int j = 0; j < boom.size(); j++) {
					temp_char.push(temp[j]);
				}
			}
		}
	}

	if (temp_char.empty()) cout << "FRULA\n";
	else {
		string output = "";
		while (!temp_char.empty()) {
			output += temp_char.top();
			temp_char.pop();
		}
		reverse(output.begin(), output.end());
		cout << output << '\n';
	}
}