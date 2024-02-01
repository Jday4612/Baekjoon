#include <iostream>
#include <queue>
using namespace std;


void spread();
void cleaner();
int R, C, T, room[50][50], add[50][50] = { 0 }, up = 0, down = 0, total = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> R >> C >> T;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> room[i][j];

            if (room[i][j] == -1) {
                if (up == 0)
                    up = i;
                else
                    down = i;
            }
            else
                total += room[i][j];
        }
    }

    for (int i = 0; i < T; i++) {
        spread();
        cleaner();
    }

    cout << total;

    return 0;
}

void spread() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (room[i][j] == -1 || room[i][j] == 0)
                continue;

            int cnt = 0;
            int dust = room[i][j] / 5;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];

                if (0 <= nx && nx < R && 0 <= ny && ny < C && room[nx][ny] != -1) {
                    add[nx][ny] += dust;
                    cnt++;
                }
            }

            add[i][j] -= dust * cnt;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            room[i][j] += add[i][j];
            add[i][j] = 0;
        }
    }
}

void cleaner() {
    total -= room[up - 1][0] + room[down + 1][0];

    for (int i = up - 1; 0 < i; i--)
        room[i][0] = room[i - 1][0];
    for (int i = 0; i < C - 1; i++)
        room[0][i] = room[0][i + 1];
    for (int i = 0; i < up; i++)
        room[i][C - 1] = room[i + 1][C - 1];
    for (int i = C - 1; 1 < i; i--)
        room[up][i] = room[up][i - 1];
    room[up][1] = 0;

    for (int j = down + 1; j < R - 1; j++)
        room[j][0] = room[j + 1][0];
    for (int j = 0; j < C - 1; j++)
        room[R - 1][j] = room[R - 1][j + 1];
    for (int j = R - 1; down < j; j--)
        room[j][C - 1] = room[j - 1][C - 1];
    for (int j = C - 1; 1 < j; j--)
        room[down][j] = room[down][j - 1];
    room[down][1] = 0;
}