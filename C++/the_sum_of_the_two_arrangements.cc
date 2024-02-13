#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[1001], B[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T, n, m, left, right, tmp;
    long long ans = 0;
    vector<int> Asum, Bsum;

    cin >> T >> n;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++) {
        tmp = A[i];
        Asum.push_back(tmp);

        for (int j = i + 1; j < n; j++) {
            tmp += A[j];
            Asum.push_back(tmp);
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++)
        cin >> B[i];

    for (int i = 0; i < m; i++) {
        tmp = B[i];
        Bsum.push_back(tmp);

        for (int j = i + 1; j < m; j++) {
            tmp += B[j];
            Bsum.push_back(tmp);
        }
    }

    sort(Bsum.begin(), Bsum.end());

    for (int i = 0; i < Asum.size(); i++) {
        tmp = T - Asum[i];
        left = lower_bound(Bsum.begin(), Bsum.end(), tmp) - Bsum.begin();
        right = upper_bound(Bsum.begin(), Bsum.end(), tmp) - Bsum.begin();

        ans += right - left;
    }

    cout << ans;

    return 0;
}