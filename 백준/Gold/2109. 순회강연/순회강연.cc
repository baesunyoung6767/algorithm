#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 10001
using namespace std;

int N;

struct compare
{
	bool operator()(pair<int, int> a, pair<int, int> b) { // day, price
		return a.first > b.first;
	}
};

priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> input; // day 기준 오름차순

int main() {
	cin >> N;
	
	int p, d;
	for (int i = 1; i <= N; i++) {
		cin >> p >> d;
		input.push({ d, p });
	}

	int result = 0;

	int size = input.size();
	for (int i = 0; i < size; i++) {
		int day = input.top().first;
		int price = input.top().second;
		input.pop();

		pq.push(price);

		if (pq.size() > day) pq.pop();
	}

	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}

	cout << result << '\n';
}