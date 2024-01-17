#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, A[1000] = { 0 }, dp[1000], len = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (A[j] < A[i])
                dp[i] = dp[i] < dp[j] + 1 ? dp[j] + 1 : dp[i];
        }

        len = len < dp[i] ? dp[i] : len;
    }

    cout << len;

    return 0;
}