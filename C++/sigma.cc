#include <iostream>
using namespace std;

#define MOD 1000000007
long long gcd(long long a, long long b);
long long getInverse(long long a, long long b);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long M, N, S, G, ans = 0;

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> N >> S;

        G = gcd(N, S);
        N /= G;
        S /= G;

        ans += S * getInverse(N, MOD - 2) % MOD;
        ans %= MOD;
    }

    cout << ans;

    return 0;
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    
    return gcd(b, a % b);
}

long long getInverse(long long a, long long b) {
    if (b == 1)
        return a;

    if (b % 2 == 1)
        return a * getInverse(a, b - 1) % MOD;

    long long z = getInverse(a, b / 2);
    return z * z % MOD;
}