#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct shark_info {
    int r, c, s, d, z, idx;
};

bool check();
void fishing(int col);
void moving();
void killing();
bool compare(int a, int b);

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };
int R, C, M, ans = 0;
vector<int> board[101][101];
vector<shark_info> shark;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> R >> C >> M;

    for (int i = 0; i < M; i++) {
        int r, c, s, d, z; // (r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기. d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽
        cin >> r >> c >> s >> d >> z;

        shark.push_back({ r, c, s, d, z, i });
        board[r][c].push_back(i);
    }

    if (M == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= C; i++) {
        if (check())
            break;
        
        fishing(i);
        moving();
        killing();
    }

    cout << ans;

    return 0;
}

bool check() {
    for (int i = 0; i < shark.size(); i++) {
        if (shark[i].z)
            return false;
    }

    return true; // 상어 크기가 모두 0
}

void fishing(int col) {
    for (int i = 1; i <= R; i++) {
        if (board[i][col].size()) {
            ans += shark[board[i][col][0]].z;
            shark[board[i][col][0]].z = 0;
            board[i][col].clear();
            break;
        }
    }
}

void moving() {
    for (int i = 0; i < shark.size(); i++) {
        if (!shark[i].z) // 상어의 크기가 0이면 넘김
            continue;

        board[shark[i].r][shark[i].c].clear();
    }

    for (int i = 0; i < shark.size(); i++) {
        if (!shark[i].z)
            continue;

        int x = shark[i].r;
        int y = shark[i].c;
        int speed = shark[i].s;
        int dir = shark[i].d;

        if (dir == 1 || dir == 2) { // 위, 아래
            int f = (R - 1) * 2; // f : 이동하고 나서 기존 위치에 도착

            if (f <= speed)
                speed %= f;

            for (int j = 0; j < speed; j++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 1) { // 위쪽 경계를 벗어남
                    dir = 2;
                    nx += 2;
                }

                if (R < nx) { // 아래쪽 경계를 벗어남
                    dir = 1;
                    nx -= 2;
                }

                x = nx;
                y = ny;
            }
        }
        else { // 오른쪽, 왼쪽
            int f = (C - 1) * 2; // f : 이동하고 나서 기존 위치에 도착

            if (f <= speed)
                speed %= f;

            for (int j = 0; j < speed; j++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (ny < 1) { // 왼쪽 경계를 벗어남
                    dir = 3;
                    ny += 2;
                }

                if (C < ny) { // 아래쪽 경계를 벗어남
                    dir = 4;
                    ny -= 2;
                }

                x = nx;
                y = ny;
            }
        }

        shark[i].r = x;
        shark[i].c = y;
        shark[i].d = dir;
        board[x][y].push_back(i);
    }
}

void killing() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (1 < board[i][j].size()) {
                sort(board[i][j].begin(), board[i][j].end(), compare);

                int b_shark = board[i][j][0];

                for (int k = 1; k < board[i][j].size(); k++) {
                    shark[board[i][j][k]].r = -1;
                    shark[board[i][j][k]].c = -1;
                    shark[board[i][j][k]].z = 0;
                }

                board[i][j].clear();
                board[i][j].push_back(shark[b_shark].idx);
            }
        }
    }
}

bool compare(int a, int b) {
    if (shark[b].z < shark[a].z)
        return true;
    
    return false;
}