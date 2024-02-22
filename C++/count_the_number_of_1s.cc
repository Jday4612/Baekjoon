#include <iostream>
using namespace std;

long long getOne(long long x);
long long A, B, cnt[55];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> A >> B;
    
    cnt[0] = 1;

    for (int i = 1; i < 55; i++)
        cnt[i] = (cnt[i - 1] * 2) + (1LL << i);

    cout << getOne(B) - getOne(A - 1);

    return 0;
}

long long getOne(long long x) {
    long long ans = x & 1;

    for (int i = 54; 0 < i; i--) { // 가장 위부터
        if (x & (1LL << i)) { // i번째가 1이라면
            ans += cnt[i - 1] + (x - (1LL << i) + 1); // (자릿수가 i개 이하인 수의 1의 개수 합) + (1___? 이상 x 이하인 수의 개수)
            x -= 1LL << i;
        }
    }

    return ans;
}