#include <iostream>
#include <queue>
using namespace std;

void bfs();
int N, M, map[1001][1001][2];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    char tmp;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> tmp;
            map[i][j][0] = tmp - '0';
        }
    }

    bfs();

    return 0;
}

void bfs() {
    queue<pair<int, pair<int, int>>> q;

    q.push({ 0, {1, 1} });

    while (!q.empty()) {
        int b = q.front().first, x = q.front().second.first, y = q.front().second.second;
        q.pop();

        if (x == N && y == M) {
            cout << map[N][M][b] + 1;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (1 <= nx && nx <= N && 1 <= ny && ny <= M) {
                if (map[nx][ny][0] == 1 && !b) {
                    map[nx][ny][b + 1] = map[x][y][b] + 1;
                    q.push({ 1, {nx, ny} });
                }
                else if (map[nx][ny][0] == 0) {
                    if (b == 1 && map[nx][ny][b])
                        continue;

                    map[nx][ny][b] = map[x][y][b] + 1;
                    q.push({ b, {nx, ny} });
                }
            }
        }
    }

    cout << -1;
}