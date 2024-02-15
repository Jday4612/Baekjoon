#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 400000

int solve(int cur, int left, int right);
int arr[100000], DP[100000][5][5], len = 0;
int p[5][5] = { { 1, 2, 2, 2, 2 }, { 0, 1, 3, 4, 3}, { 0, 3, 1, 3, 4}, { 0, 4, 3, 1, 3}, { 0, 3, 4, 3, 1} };

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n = 1, ans;

    while (true) {
        cin >> n;

        if (n == 0)
            break;

        arr[len++] = n;
    }

    memset(DP, -1, sizeof(DP));

    ans = solve(0, 0, 0);
    cout << ans;

    return 0;
}

int solve(int cur, int left, int right) {
    if (cur == len)
        return 0;

    if (left != 0 && right != 0 && left == right)
        return INF;

    if (DP[cur][left][right] != -1)
        return DP[cur][left][right];

    return DP[cur][left][right] = min(solve(cur + 1, arr[cur], right) + p[left][arr[cur]], solve(cur + 1, left, arr[cur]) + p[right][arr[cur]]);
}