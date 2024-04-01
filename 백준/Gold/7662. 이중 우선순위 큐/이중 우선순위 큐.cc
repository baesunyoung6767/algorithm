#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        priority_queue<int, vector<int>, greater<int>> pqa; // 오름차순
        priority_queue<int> pqd; // 내림차순 
        map<int, int> m;
        int K;
        cin >> K;

        char cmd;
        int N;
        for (int i = 0; i < K; i++) {
            cin >> cmd >> N;

            if (cmd == 'I') {
                pqa.push(N);
                pqd.push(N);
                m[N]++;
            }
            else {
                if (N < 0) {
                    if (!pqa.empty()) {
                        m[pqa.top()]--;
                        pqa.pop();
                    }
                }
                else {
                    if (!pqd.empty()) {
                        m[pqd.top()]--;
                        pqd.pop();
                    }
                }
                while (!pqa.empty() && m[pqa.top()] == 0) pqa.pop();
                while (!pqd.empty() && m[pqd.top()] == 0) pqd.pop();
            }
        }
        if (pqd.empty() || pqa.empty()) cout << "EMPTY\n";
        else {
            int maxNum = pqd.top();
            int minNum = pqa.top();
            cout << maxNum << ' ' << minNum << '\n';
        }
    }
}