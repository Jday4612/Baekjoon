#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 16000000
int dfs(int cur, int visit);
int N, W[16][16], dp[16][1 << 16];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> W[i][j];

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1);

    return 0;
}

int dfs(int cur, int visit) {
    if (visit == (1 << N) - 1) {
        if (W[cur][0] == 0)
            return INF;

        return W[cur][0];
    }

    if (dp[cur][visit] != -1)
        return dp[cur][visit];

    dp[cur][visit] = INF;

    for (int i = 0; i < N; i++) {
        if (!W[cur][i])
            continue;

        if ((visit & (1 << i)) == (1 << i))
            continue;

        dp[cur][visit] = min(dp[cur][visit], W[cur][i] + dfs(i, visit | 1 << i));
    }

    return dp[cur][visit];
}