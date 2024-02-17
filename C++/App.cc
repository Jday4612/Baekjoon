#include <iostream>
#include <algorithm>
using namespace std;

int m[101], c[101], DP[10001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, ans = 0;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> m[i];

    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        ans += c[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = ans; c[i] <= j ; j--) {
            if (c[i] <= j)
                DP[j] = max(DP[j], DP[j - c[i]] + m[i]); // i번째 메모리 포함/미포함 & 같은 비용으로 최대 메모리 용량
        }
    }

    for (int i = 0; i <= ans; i++) { // 적은 비용부터 최대 용량 비교
        if (M <= DP[i]) {
            cout << i;
            break;
        }
    }

    return 0;
}