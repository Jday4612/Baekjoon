#include <iostream>
using namespace std;

void dfs(int x, int y, int dir);
int N, ans = 0, map[17][17];
int dx[3] = { 0, 1, 1 }, dy[3] = { 1, 1, 0 };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];

    dfs(1, 2, 0);
    cout << ans;

    return 0;
}

void dfs(int x, int y, int dir) {
    if (x == N && y == N) {
        ans++;
        return;
    }

    for (int i = 0; i < 3; i++) {
        if ((dir == 2 && i == 0) || (dir == 0 && i == 2))
            continue;

        if (i == 1 && (map[x][y + 1] == 1 || map[x + 1][y] == 1))
            continue;

        int nx = x + dx[i], ny = y + dy[i];

        if (0 < nx && nx <= N && 0 < ny && ny <= N && map[nx][ny] == 0)
            dfs(nx, ny, i);
    }
}