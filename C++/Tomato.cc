#include <iostream>
#include <queue>
using namespace std;

int N, M, H, box[100][100][100], visited[100][100][100];
queue<pair<int, pair<int, int>>> q;

int bfs() {
    int dx[6] = { 0, 0, 1, -1, 0, 0 };
    int dy[6] = { -1, 1, 0, 0, 0, 0 };
    int dz[6] = { 0, 0, 0, 0, 1, -1 };
    int maxDays = 0;

    while (!q.empty()) {
        int z = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;

        q.pop();

        for (int i = 0; i < 6; ++i) {
            int cz = z + dz[i];
            int cx = x + dx[i];
            int cy = y + dy[i];

            if (0 <= cx && cx < N && 0 <= cy && cy < M && 0 <= cz && cz < H && box[cz][cx][cy] == 0) {
                box[cz][cx][cy] = 1;
                visited[cz][cx][cy] = visited[z][x][y] + 1;
                q.push({ cz, { cx, cy } });
                maxDays = max(maxDays, visited[cz][cx][cy]);
            }
        }
    }

    return maxDays;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];

                if (box[i][j][k] == 1) {
                    q.push({ i, { j, k } });
                    visited[i][j][k] = 0;
                }
            }
        }
    }

    int result = bfs();

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << result;

    return 0;
}