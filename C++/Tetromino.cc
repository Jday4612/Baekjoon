#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans = 0, paper[500][500], visited[500][500] = { 0 };
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { -1, 1, 0, 0 };

void solve(int x, int y, int cnt, int sum);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> paper[i][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 1;
            solve(i, j, 1, paper[i][j]);
            visited[i][j] = 0;
        }
    }

    cout << ans;

    return 0;
}

void solve(int x, int y, int cnt, int sum) {
    if (cnt == 4) {
        if (ans < sum)
            ans = sum;
    }
    else {
        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i], cy = y + dy[i];

            if (0 <= cx && cx < N && 0 <= cy && cy < M && visited[cx][cy] == 0) {
                visited[cx][cy] = 1;
                solve(cx, cy, cnt + 1, sum + paper[cx][cy]);
                visited[cx][cy] = 0;
            }
        }

        // 'ㅏ'
        if (0 <= x - 1 && x + 1 < N && y + 1 < M)
            ans = max(ans, paper[x - 1][y] + paper[x][y] + paper[x][y + 1] + paper[x + 1][y]);

        // 'ㅓ'
        if (0 <= x - 1 && x + 1 < N && 0 <= y - 1)
            ans = max(ans, paper[x - 1][y] + paper[x][y] + paper[x][y - 1] + paper[x + 1][y]);

        // 'ㅗ'
        if (0 <= x - 1 && 0 <= y - 1 && y + 1 < M)
            ans = max(ans, paper[x][y - 1] + paper[x][y] + paper[x - 1][y] + paper[x][y + 1]);

        // 'ㅜ'
        if (x + 1 < N && 0 <= y - 1 && y + 1 < M)
            ans = max(ans, paper[x][y - 1] + paper[x][y] + paper[x + 1][y] + paper[x][y + 1]);
    }
}