#include <iostream>
#include <algorithm>
#define MAX 201
using namespace std;

int N;
int child[MAX] = { 0 };
int len[MAX] = { 0 };

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> child[i];
		len[i] = 1;
	}

	int check = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (child[i] > child[j] && len[i] <= len[j]) len[i] = len[j] + 1;
		}
	}
	sort(len, len + N);
	cout << N - len[N - 1] << '\n';

}