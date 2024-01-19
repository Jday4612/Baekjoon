#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, x1, x2, y1, y2, ans, table[1025][1025];

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++){
            cin >> table[i][j];
            table[i][j] += table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1];
        }

    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        ans = table[x2][y2] - table[x1 - 1][y2] - table[x2][y1 - 1] + table[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }

    return 0;
}