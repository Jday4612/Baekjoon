#include <iostream>
#include <algorithm>
using namespace std;

void DFS(int x, int y, int cnt, int color);
int N, board[10][10], ans[2] = { 0 }, l[20] = { 0 }, r[20] = { 0 };

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    DFS(0, 0, 0, 0);
    DFS(0, 1, 0, 1);

    cout << ans[0] + ans[1];

    return 0;
}

void DFS(int x, int y, int cnt, int color) {
    if (y >= N) {
        x++;

        if (y % 2 == 0)
            y = 1;
        else
            y = 0;
    }

    if (x >= N) {
        ans[color] = max(ans[color], cnt);
        return;
    }

    if (board[x][y] && !l[x - y + N] && !r[x + y]) {
        l[x - y + N] = r[x + y] = 1;
        DFS(x, y + 2, cnt + 1, color);
        l[x - y + N] = r[x + y] = 0;
    }

    DFS(x, y + 2, cnt, color);
}