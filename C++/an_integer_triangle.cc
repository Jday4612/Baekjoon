#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, arr[501][501] = { 0 }, ans = 0;

    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1)
                arr[i][j] += arr[i - 1][j];
            else if (i == j)
                arr[i][j] += arr[i - 1][j - 1];
            else
                arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);

            ans = max(ans, arr[i][j]);
        }
    }

    cout << ans;

    return 0;
}