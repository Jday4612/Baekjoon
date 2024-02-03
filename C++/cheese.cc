#include <iostream>
#include <queue>
using namespace std;

void checkAir();
int N, M, ans = 0, paper[100][100], visited[100][100], air[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> paper[i][j];

    while (true) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                visited[i][j] = air[i][j] = 0;

        checkAir();

        bool melted = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (air[i][j] > 1) {
                    paper[i][j] = 0;
                    melted = true;
                }
            }
        }

        if (melted)
            ans++;
        else
            break;
    }

    cout << ans;

    return 0;
}

void checkAir() {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny <= M && visited[nx][ny] == 0) {
                if (paper[nx][ny] == 1)
                    air[nx][ny]++;
                else {
                    visited[nx][ny] = 1;
                    q.push({ nx, ny });
                }
            }
        }
    }
}