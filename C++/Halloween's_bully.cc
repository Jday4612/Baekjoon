#include <iostream>
#include <algorithm>
using namespace std;

int Find(int x);
void Union(int x, int y);
int N, M, K, c[30001], parent[30001], f[30001] = { 0 }, dp[3000] = { 0 };

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, r;

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        parent[i] = i;
        f[i] = 1;
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        Union(a, b);
    }

    for (int i = 1; i <= N; i++) {
        if (parent[i] != i) {
            r = Find(i);
            c[r] += c[i];
            f[r] += f[i]; // i의 친구는 r의 친구도 됨
        }
    }

    for (int i = 1; i <= N; i++) {
        if (parent[i] != i)
            continue;

        for (int j = K - 1; 0 <= j - f[i]; j--)
            dp[j] = max(dp[j], dp[j - f[i]] + c[i]);
    }

    cout << dp[K - 1];

    return 0;
}

int Find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
}