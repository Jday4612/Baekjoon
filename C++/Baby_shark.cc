#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs();
int N, baby = 2, bx, by, space[20][20], ans = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
bool eat = false;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cnt = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];

            if (space[i][j] == 9) {
                bx = i;
                by = j;
                space[i][j] = 0;
            }
        }
    }

    while (true) {
        bfs();

        if (eat) {
            cnt++;
            space[bx][by] = 0;
            eat = false;

            if (baby == cnt) {
                baby++;
                cnt = 0;
            }
        }
        else
            break;
    }

    cout << ans;

    return 0;
}

void bfs() {
    int visited[20][20] = { 0 }, time = 0;
    queue<pair<int, pair<int, int>>> q;

    q.push({ 0, {bx, by} });
    visited[bx][by] = 1;

    while (!q.empty()) {
        int t = q.front().first, x = q.front().second.first, y = q.front().second.second;

        if (0 < space[x][y] && space[x][y] < baby && time == t) {
            if (x < bx || (x == bx && y < by)) {
                bx = x;
                by = y;
                continue;
            }
        }

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < N && visited[nx][ny] == 0) {
                if (space[nx][ny] <= baby) {
                    visited[nx][ny] = 1;

                    if (0 < space[nx][ny] && space[nx][ny] < baby && !eat) {
                        eat = true;
                        bx = nx;
                        by = ny;
                        time = t + 1;
                        ans += time;
                    }
                    else
                        q.push({ t + 1, {nx, ny} });
                }
            }
        }
    }
}