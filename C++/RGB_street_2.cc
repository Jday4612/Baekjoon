#include <iostream>
#include <algorithm>
using namespace std;

int N, house[1001][3], DP[1001][3], ans = 1000000;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> house[i][0] >> house[i][1] >> house[i][2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == i)
                DP[1][j] = house[1][j];
            else
                DP[1][j] = 1001;
        }

        for (int k = 2; k <= N; k++) {
            DP[k][0] = house[k][0] + min(DP[k - 1][1], DP[k - 1][2]);
            DP[k][1] = house[k][1] + min(DP[k - 1][0], DP[k - 1][2]);
            DP[k][2] = house[k][2] + min(DP[k - 1][0], DP[k - 1][1]);
        }

        for (int z = 0; z < 3; z++) {
            if (i == z)
                continue;
            else
                ans = min(ans, DP[N][z]);
        }
    }

    cout << ans;

    return 0;
}