#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int dp[50001] = { 0, 1, };
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        dp[i] = INT_MAX;

        for (int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }

    cout << dp[n];

    return 0;
}