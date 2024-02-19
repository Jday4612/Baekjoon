#include <iostream>
#include <string>
using namespace std;

void dfs(int x, int y);
int N, M, ans = 0, map[1000][1000], visited[1000][1000] = { 0 };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> s;

        for (int j = 0; j < M; j++) {
            if (s[j] == 'L')
                map[i][j] = 0;
            else if (s[j] == 'R')
                map[i][j] = 1;
            else if (s[j] == 'D')
                map[i][j] = 2;
            else if (s[j] == 'U')
                map[i][j] = 3;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0)
                dfs(i, j);
        }
    }
    
    cout << ans;

    return 0;
}

void dfs(int x, int y) {
    visited[x][y] = 1;

    int nx = x + dx[map[x][y]], ny = y + dy[map[x][y]];

    if (visited[nx][ny] == 1)
        ans++;

    if (visited[nx][ny] == 0)
        dfs(nx, ny);

    visited[x][y] = 2;
}