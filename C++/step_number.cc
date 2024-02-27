#include <iostream>
using namespace std;

#define DIV 1000000000
int dfs(int num, int idx, int bit);
int N, dp[10][101][1 << 10] = { 0 }; // 1 << 10 == 1024

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int ans = 0;

    cin >> N;

    for (int i = 1; i <= 9; i++) { // 0으로 시작하는 수 X
        ans += dfs(i, 1, 1 << i);
        ans %= DIV;
    }

    cout << ans;

    return 0;
}

int dfs(int num, int idx, int bit) {
    if (dp[num][idx][bit])
        return dp[num][idx][bit];

    if (idx == N) {
        if (bit == 1023) // 0 ~ 9까지 다 한 개씩은 있음
            return 1;
        else
            return 0;
    }

    int tmp = 0;

    if (num < 9)
        tmp += dfs(num + 1, idx + 1, bit | 1 << (num + 1)); // 1 ~ 9

    if (0 < num)
        tmp += dfs(num - 1, idx + 1, bit | 1 << (num - 1)); // 0 ~ 8

    tmp %= DIV;

    return dp[num][idx][bit] = tmp;
}