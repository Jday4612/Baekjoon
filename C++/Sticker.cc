#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T, n, sticker[2][100001], dp[2][100001];

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> n;

        for (int j = 0; j < 2; j++) {
            for (int k = 1; k <= n; k++)
                cin >> sticker[j][k];
        }

        dp[0][0] = dp[1][0] = 0;
        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];

        for (int j = 2; j <= n; j++) {
            dp[0][j] = max(dp[1][j - 2], dp[1][j - 1]) + sticker[0][j];
            dp[1][j] = max(dp[0][j - 2], dp[0][j - 1]) + sticker[1][j];
        }

        cout << max(dp[0][n], dp[1][n]) << "\n";
    }

    return 0;
}