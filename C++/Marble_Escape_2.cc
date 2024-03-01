#include <iostream>
#include <queue>
using namespace std;

struct moving {
    int rx, ry, bx, by, cnt;
};

void bfs();
int N, M, Rx, Ry, Bx, By, visit[10][10][10][10] = { 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
char board[10][10];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];

            if (board[i][j] == 'R') {
                Rx = i;
                Ry = j;
            }
            else if (board[i][j] == 'B') {
                Bx = i;
                By = j;
            }
        }
    }

    bfs();

    return 0;
}

void bfs() {
    queue<moving> q;

    q.push({ Rx, Ry, Bx, By, 0 });
    visit[Rx][Ry][Bx][By] = 1;

    while (!q.empty()) {
        int crx = q.front().rx;
        int cry = q.front().ry;
        int cbx = q.front().bx;
        int cby = q.front().by;
        int ccnt = q.front().cnt;
        
        q.pop();

        if (10 <= ccnt)
            break;

        for (int i = 0; i < 4; i++) {
            int nrx = crx, nry = cry, nbx = cbx, nby = cby, ncnt = ccnt + 1;
            int rcnt = 0, bcnt = 0;

            while (board[nrx + dx[i]][nry + dy[i]] != '#' && board[nrx][nry] != 'O') { // 이동 전 : 탈출구가 아니여야 함, / 이동 후 : 벽이 아니여야 함 / 기울이기로 이동
                nrx += dx[i];
                nry += dy[i];
                rcnt++;
            }

            while (board[nbx + dx[i]][nby + dy[i]] != '#' && board[nbx][nby] != 'O') {
                nbx += dx[i];
                nby += dy[i];
                bcnt++;
            }

            if (board[nbx][nby] == 'O') // 파란 구슬 탈출 X
                continue;

            if (board[nrx][nry] == 'O') { // 빨간 구슬 탈출
                cout << ncnt;
                return;
            }

            if (nrx == nbx && nry == nby) { // 구슬이 있는 위치가 같아지면 빨간 구슬만 탈출시킬 수 있는 방법이 존재하지 않음
                if (bcnt < rcnt) {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            if (visit[nrx][nry][nbx][nby])
                continue;

            visit[nrx][nry][nbx][nby] = 1;
            q.push({ nrx, nry, nbx, nby, ncnt });
        }
    }

    cout << -1;
}