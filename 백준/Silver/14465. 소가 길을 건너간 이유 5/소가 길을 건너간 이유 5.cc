#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int N, K, B;
int light[MAX] = { 0 };
int cnt = 0, result = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie();

	cin >> N >> K >> B;

	int temp;
	for (int i = 0; i < B; i++) {
		cin >> temp;
		light[temp] = 1;
	}

	for (int i = 1; i <= K; i++) cnt += light[i];
	result = cnt;
	
	int j = 1;
	for (int i = K + 1; i <= N; i++) {
		cnt -= light[j++];
		cnt += light[i];
		result = min(result, cnt);
	}

	cout << result << '\n';
}