#include <iostream>
#include <queue>
using namespace std;

int N, M, maze[100][100], visited[100][100] = { 0 };

void bfs();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> s;

        for (int j = 0; j < M; j++)
            maze[i][j] = s[j] - '0';
    }

    bfs();

    cout << visited[N - 1][M - 1];

    return 0;
}

void bfs() {
    int directX[4] = {0, 0, 1, -1}, directY[4] = {-1, 1, 0, 0};
    queue<pair<int, int>> q;

    visited[0][0] = 1;
    q.push({ 0, 0 });

    while (!q.empty()) {
        int fx = q.front().first, fy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = fx + directX[i], y = fy + directY[i];

            if (0 <= x && x < N && 0 <= y && y < M && visited[x][y] == 0 && maze[x][y] == 1) {
                visited[x][y] = visited[fx][fy] + 1;
                q.push({ x, y });
            }
        }
    }
}