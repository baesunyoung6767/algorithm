#include <iostream>
#include <algorithm>
#include <math.h>
#define MAX 100001
using namespace std;

int N;
long long int arr[MAX] = { 0 };
long long int resultA, resultB;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	int start = 0;
	int end = N-1;
    resultA = arr[start];
    resultB = arr[end];
    int minResult = abs(arr[start] + arr[end]);
    
	while (start < end) {
		int temp = arr[start] + arr[end];
		int output = abs(temp);
		if (temp == 0) {
			resultA = arr[start];
			resultB = arr[end];
			break;
		}
		else {
			if (minResult > output) {
				minResult = output;
				resultA = arr[start];
				resultB = arr[end];
			}

			if (temp < 0) {
				start++;
			}
			else {
				end--;
			}
		}
	}

	cout << resultA << ' ' << resultB << '\n';
	return 0;
}
