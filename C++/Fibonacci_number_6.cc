#include <iostream>
#include <map>
using namespace std;

#define DIV 1000000007
long long fibo(long long x);
map<long, long> m;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long n, ans;

    cin >> n;

    m[0] = 0;
    m[1] = m[2] = 1;

    ans = fibo(n);
    cout << ans;

    return 0;
}

long long fibo(long long x) {
    if (m[x])
        return m[x];

    long long tmp;

    if (x % 2 == 0)
        tmp = (fibo(x / 2) * (fibo(x / 2 - 1) + fibo(x / 2 + 1))) % DIV;
    else
        tmp = ((fibo((x - 1) / 2) * fibo((x - 1) / 2)) % DIV) + ((fibo((x + 1) / 2) * fibo((x + 1) / 2)) % DIV) % DIV;

    return m[x] = tmp % DIV;
}