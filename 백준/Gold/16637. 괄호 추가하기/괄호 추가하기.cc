#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string calcdata;
int result = -987654321;

int calc(int a, int b, char oper) {
	int temp = 0;
	switch (oper)
	{
	case '+':
		temp = a + b;
		break;
	case '-':
		temp = a - b;
		break;
	case '*':
		temp = a * b;
	}
	return temp;
}

void check(int beforenum, int cnt) {
	if (cnt >= N) {
		//종료
		result = max(result, beforenum);
		return;
	}

	char oper;
	if (cnt == 0) oper = '+';
	else oper = calcdata[cnt - 1];

	if (cnt <= N - 2) {
		int output = calc(calcdata[cnt] - '0', calcdata[cnt + 2] - '0', calcdata[cnt + 1]);
		int cur1 = calc(beforenum, output, oper);
		check(cur1, cnt + 4);
	}
	int cur2 = calc(beforenum, calcdata[cnt] - '0', oper);
	check(cur2, cnt + 2);
}

int main() {
	cin >> N >> calcdata;

	check(0, 0);
	cout << result << '\n';
}