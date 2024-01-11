#include <iostream>
#include <queue>
using namespace std;

int N, M, x, y, cnt = 0, visited[600][600];
char campus[600][600];

void bfs();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> campus[i][j];

            if (campus[i][j] == 'I') {
                x = i;
                y = j;
            }
        }

    bfs();
    
    if (cnt == 0)
        cout << "TT";
    else
        cout << cnt;

    return 0;
}

void bfs() {
    int directX[4] = {0, 0, 1, -1};
    int directY[4] = { -1, 1, 0, 0 };

    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = 1;

    while (!q.empty()) {
        int fX = q.front().first, fY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cX = fX + directX[i], cY = fY + directY[i];

            if (0 <= cX && cX < N && 0 <= cY && cY < M && visited[cX][cY] == 0 && campus[cX][cY] != 'X') {
                if (campus[cX][cY] == 'P')
                    cnt++;

                visited[cX][cY] = 1;
                q.push({ cX, cY });
            }
        }
    }
}