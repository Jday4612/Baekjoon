#include <iostream>
#include <algorithm>
using namespace std;

#define INF 10000000

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, a, b, c, bus[101][101];

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                bus[i][j] = 0;
            else
                bus[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        bus[a][b] = min(bus[a][b], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                bus[j][k] = min(bus[j][k], bus[j][i] + bus[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (bus[i][j] == INF)
                cout << "0 ";
            else
                cout << bus[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}