#include <iostream>
#include <algorithm>
using namespace std;

int N, K, W[101], V[101], dp[101][100001] = { 0 };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (W[i] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][K];

    return 0;
}