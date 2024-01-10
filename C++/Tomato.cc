#include <iostream>
#include <queue>
using namespace std;

int N, M, box[1000][1000], visited[1000][1000];
queue<pair<int, int>> q;

int bfs() {
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { -1, 1, 0, 0 };
    int maxDays = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int cx = x + dx[i];
            int cy = y + dy[i];

            if (0 <= cx && cx < N && 0 <= cy && cy < M && box[cx][cy] == 0) {
                box[cx][cy] = 1;
                visited[cx][cy] = visited[x][y] + 1;
                q.push({ cx, cy });
                maxDays = max(maxDays, visited[cx][cy]);
            }
        }
    }

    return maxDays;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> M >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> box[i][j];

            if (box[i][j] == 1) {
                q.push({ i, j });
                visited[i][j] = 0;
            }
        }
    }

    int result = bfs();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (box[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << result;

    return 0;
}