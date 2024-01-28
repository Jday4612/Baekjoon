#include <iostream>
using namespace std;

int N, A[1000],dp_l[1000], dp_r[1000];
void solve();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve();

    return 0;
}

void solve() {
    int ans = 0;

    for (int i = 0; i < N; i++) {
        dp_l[i] = 1;

        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && dp_l[i] < dp_l[j] + 1)
                dp_l[i] = dp_l[j] + 1;
        }
    }

    for (int i = N - 1; 0 <= i; i--) {
        dp_r[i] = 1;

        for (int j = N - 1; i < j; j--) {
            if (A[j] < A[i] && dp_r[i] < dp_r[j] + 1)
                dp_r[i] = dp_r[j] + 1;
        }
    }

    for (int i = 0; i < N; i++)
        if (ans < dp_l[i] + dp_r[i] - 1)
            ans = dp_l[i] + dp_r[i] - 1;

    cout << ans;
}