#include <iostream>
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	string command;
	int x, num = 0;

	for (int t = 0; t < N; t++) {
		cin >> command;

		if (command == "add") {
			cin >> x;
			num = num | 1 << (x - 1);
		}
		else if (command == "remove") {
			cin >> x;
			num = num & ~(1 << (x - 1));
		}
		else if (command == "check") {
			cin >> x;
			if (num & (1 << (x - 1))) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (command == "toggle") {
			cin >> x;
			if (num & (1 << (x - 1))) num = num & ~(1 << (x - 1));
			else num = num | 1 << (x - 1);
		}
		else if (command == "all") {
			num = (1 << 20) - 1;
		}
		else if (command == "empty") {
			num = 0;
		}
	}
	return 0;
}