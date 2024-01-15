#include <iostream>
#include <string.h>
using namespace std;

int N, visited[100][100] = { 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
char grid[100][100];

void dfs(int x, int y);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cnt = 0;
    string s;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;

        for (int j = 0; j < N; j++)
            grid[i][j] = s[j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt << " ";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'R')
                grid[i][j] = 'G';
        }
    }

    memset(visited, 0, sizeof(visited));
    cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}

void dfs(int x, int y) {
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];

        if (0 <= cx && cx < N && 0 <= cy && cy < N && grid[cx][cy] == grid[x][y] && visited[cx][cy] == 0) {
            dfs(cx, cy);
        }
    }
}