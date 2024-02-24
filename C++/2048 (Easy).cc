#include <iostream>
#include <queue>
using namespace std;

void dfs(int times);
void shift(int dir);
int N, board[20][20], ans = 0;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    dfs(0);

    cout << ans;

    return 0;
}

void dfs(int times) {
    if (times == 5)
        return;

    int newBoard[20][20];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            newBoard[i][j] = board[i][j]; // 원본 복사

    for (int i = 0; i < 4; i++) {
        shift(i); // 상하좌우 중 한 방향으로 이동

        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (ans < board[x][y])
                    ans = board[x][y]; // 가장 큰 값 저장
            }
        }

        dfs(times + 1);

        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++)
                board[x][y] = newBoard[x][y]; // 다른 방향으로 이동하기 위해 재복사
        }
    }
}

void shift(int dir) {
    queue<int> q;

    if (dir == 0) { //상
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[j][i])
                    q.push(board[j][i]); // 빈 칸이 아닌 곳의 블록 값

                board[j][i] = 0;
            }

            int idx = 0;

            while (!q.empty()) {
                int data = q.front();
                q.pop();

                if (board[idx][i] == 0)
                    board[idx][i] = data;
                else if (board[idx][i] == data) {
                    board[idx][i] *= 2;
                    idx++;
                }
                else {
                    idx++;
                    board[idx][i] = data;
                }
            }
        }
    }
    else if (dir == 1) { //하
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; 0 <= j; j--) {
                if (board[j][i])
                    q.push(board[j][i]);

                board[j][i] = 0;
            }

            int idx = N - 1;

            while (!q.empty()) {
                int data = q.front();
                q.pop();

                if (board[idx][i] == 0)
                    board[idx][i] = data;
                else if (board[idx][i] == data) {
                    board[idx][i] *= 2;
                    idx--;
                }
                else {
                    idx--;
                    board[idx][i] = data;
                }
            }
        }
    }
    else if (dir == 2) { //좌
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j])
                    q.push(board[i][j]);

                board[i][j] = 0;
            }

            int idx = 0;

            while (!q.empty()) {
                int data = q.front();
                q.pop();

                if (board[i][idx] == 0)
                    board[i][idx] = data;
                else if (board[i][idx] == data) {
                    board[i][idx] *= 2;
                    idx++;
                }
                else {
                    idx++;
                    board[i][idx] = data;
                }
            }
        }
    }
    else if (dir == 3) { //우
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; 0 <= j; j--) {
                if (board[i][j])
                    q.push(board[i][j]);

                board[i][j] = 0;
            }

            int idx = N - 1;

            while (!q.empty()) {
                int data = q.front();
                q.pop();

                if (board[i][idx] == 0)
                    board[i][idx] = data;
                else if (board[i][idx] == data) {
                    board[i][idx] *= 2;
                    idx--;
                }
                else {
                    idx--;
                    board[i][idx] = data;
                }
            }
        }
    }
}