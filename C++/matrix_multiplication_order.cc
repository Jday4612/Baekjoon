#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int matrix[501][2], dp[501][501] = { 0 };

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> matrix[i][0] >> matrix[i][1];

    for (int i = 1; i < N; i++) { // 간격 : 1 ~ N - 1
        for (int j = 1; i + j <= N; j++) {
            dp[j][i + j] = INT_MAX;

            for (int k = j; k <= i + j; k++)
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
        }
    }

    cout << dp[1][N];

    return 0;
}