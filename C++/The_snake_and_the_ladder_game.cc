#include <iostream>
#include <queue>
using namespace std;

int board[101] = { 0 }, visited[101] = { 0 };
void bfs(int a, int b);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, x, y, u, v;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        board[x] = y;
    }

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        board[u] = v;
    }

    bfs(1, 0);

    return 0;
}

void bfs(int a, int b) {
    queue<pair<int, int>> q;

    q.push({ a, b });
    visited[1] = 1;

    while (!q.empty()) {
        int loc = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next_loc = loc + i;

            if (next_loc == 100) {
                cout << cnt + 1;
                return;
            }
            else if (next_loc < 100) {
                while (board[next_loc] != 0) {
                    next_loc = board[next_loc]; // 사다리, 뱀이 아닐 때까지 계속 이동
                }

                if (visited[next_loc] == 0) {
                    visited[next_loc] = 1;
                    q.push({ next_loc, cnt + 1 });
                }
            }
        }
    }
}