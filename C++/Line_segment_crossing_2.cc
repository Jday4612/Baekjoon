#include <iostream>
#include <vector>
using namespace std;

int CCW(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C);
bool solve(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C, pair<long long, long long> D);
vector<pair<long long, long long>> v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    long long x, y;
    int ans;

    for (int i = 0; i < 4; i++) {
        cin >> x >> y;
        v.push_back({ x, y });
    }

    ans = solve(v[0], v[1], v[2], v[3]);

    cout << ans;

    return 0;
}

int CCW(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C) {
    long long tmp = (A.first * B.second + B.first * C.second + C.first * A.second) - (B.first * A.second + C.first * B.second + A.first * C.second);

    if (tmp > 0) // 반시계
        return 1;
    else if (tmp < 0) // 시계
        return -1;
    else
        return 0;
}

bool solve(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C, pair<long long, long long> D) {
    int tmp1 = CCW(A, B, C) * CCW(A, B, D);
    int tmp2 = CCW(C, D, A) * CCW(C, D, B);

    if (tmp1 == 0 && tmp2 == 0) {
        if (B < A)
            swap(A, B);

        if (D < C)
            swap(C, D);

        if (A <= D && C <= B) // 교차 O
            return true;
        else
            return false;
    }
    else
        return (tmp1 <= 0 && tmp2 <= 0); // 둘 중 하나라도 양수이면 교차 X
}