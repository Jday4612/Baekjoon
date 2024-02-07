#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long double solve(int a, int b);
int N;
vector<pair<int, int>> v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b;
    long double ans = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }

    for (int j = 1; j < N - 1; j++)
        ans += solve(j, j + 1);

    cout << fixed;
    cout.precision(1);
    cout << abs(ans);

    return 0;
}

long double solve(int a, int b) {
    long double x1 = v[0].first, y1 = v[0].second;
    long double x2 = v[a].first, y2 = v[a].second;
    long double x3 = v[b].first, y3 = v[b].second;

    return ((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) / 2;
}