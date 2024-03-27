#include <iostream>

using namespace std;

long long T, N;
int main() {

    cin >> T;

    while (T--) {
        cin >> N;
        long long exp = N * (N + 1) / 2; // n마리 처치 후 얻을 수 있는 경험치

        long long start = 1;
        long long end = 1000000000;
        long long mid = 0;
        long long result = 0;
        while (start <= end) {
            mid = (start + end) / 2;

            // mid 레벨까지 오는데 필요한 경험치
            long long need = mid * mid - mid;

            if (exp < need) end = mid - 1;
            else {
                start = mid + 1;
                result = mid;
            }
        }
        cout << result << '\n';

    }
}