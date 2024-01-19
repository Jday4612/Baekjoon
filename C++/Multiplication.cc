#include <iostream>
using namespace std;

long int solve(long int A, long int B, long int C);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long int A, B, C, ans;

    cin >> A >> B >> C;
    ans = solve(A, B, C);

    cout << ans;

    return 0;
}

long int solve(long int A, long int B, long int C) {
    if (B == 1)
        return A % C;

    long int t = solve(A, B / 2, C);

    if (B % 2 == 1) // 홀수
        return (t * t % C) * A % C;
    else
        return t * t % C;
}