#include <iostream>
using namespace std;

void draw(int len, int x, int y);
char star[3072][6143];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 2 * N - 1; j++)
            star[i][j] = ' ';

    draw(N, 0, N - 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++)
            cout << star[i][j];
        cout << "\n";
    }

    return 0;
}

void draw(int len, int x, int y) {
    if (len == 3) {
        star[x][y] = '*';

        star[x + 1][y - 1] = '*';
        star[x + 1][y + 1] = '*';


        for (int i = 0; i < 5; i++)
            star[x + 2][y - 2 + i] = '*';
    }
    else {
        draw(len / 2, x, y);
        draw(len / 2, x + len / 2, y - len / 2);
        draw(len / 2, x + len / 2, y + len / 2);
    }
}