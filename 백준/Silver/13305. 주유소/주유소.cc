#include <iostream>
#include<algorithm>

#define MAX 1000000000

using namespace std;

long long dist[100001];
long long price[100001];
long long greedy;
long long sum;

int main() {
	int n = 0;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		cin >> dist[i];
	}

	for(int i = 0; i < n; i++) {
		cin >> price[i];
	}
	greedy = MAX;

	for (int i = 0; i < n; i++) {
		if (greedy > price[i])
			greedy = price[i];
		sum += greedy * dist[i];
	}

	cout << sum;
}