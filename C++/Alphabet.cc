#include <iostream>
using namespace std;

int R, C, ans = 0, visited[26] = { 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
char board[20][20];
void dfs(int len, int x, int y);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> board[i][j];

    visited[board[0][0] - 'A'] = 1;
    dfs(1, 0, 0);

    cout << ans;

    return 0;
}

void dfs(int len, int x, int y) {
    if (ans < len)
        ans = len;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (0 <= nx && nx < R && 0 <= ny && ny < C && visited[board[nx][ny] - 'A'] == 0) {
            visited[board[nx][ny] - 'A'] = 1;
            dfs(len + 1, nx, ny);
            visited[board[nx][ny] - 'A'] = 0;
        }
    }
}