#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, r, g, b, home[1001][3];

    cin >> N;
    home[0][0] = home[0][1] = home[0][2] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> r >> g >> b;

        home[i][0] = min(home[i - 1][1], home[i - 1][2]) + r;
        home[i][1] = min(home[i - 1][0], home[i - 1][2]) + g;
        home[i][2] = min(home[i - 1][0], home[i - 1][1]) + b;
    }

    cout << min(home[N][0], min(home[N][1], home[N][2]));

    return 0;
}