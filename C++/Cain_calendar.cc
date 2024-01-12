#include <iostream>
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T, M, N, x, y, k, MAX;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> M >> N >> x >> y;
        
        k = -1;
        MAX = lcm(M, N);

        for (int i = x; i <= MAX; i += M) {
            if (i % N == y || (i % N == 0 && N == y)) {
                k = i;
                break;
            }
        }

        cout << k << "\n";
    }

    return 0;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}