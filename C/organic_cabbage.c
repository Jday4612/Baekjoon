#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cabbage(int X, int Y);
int M, N, field[50][50] = { 0 };

int main() {
    int T, K, X, Y, cnt;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &M, &N, &K);

        for (int j = 0; j < K; j++) {
            scanf("%d %d", &X, &Y);
            field[X][Y] = 1;
        }

        cnt = 0;
        for (int j = 0; j < M; j++) {
            for (int z = 0; z < N; z++) {
                if (field[j][z] == 1) {
                    cabbage(j, z);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}

int cabbage(int X, int Y) {
    field[X][Y] = 0;

    if (X + 1 < M && field[X + 1][Y] == 1) {
        cabbage(X + 1, Y);
    }

    if (Y + 1 < N && field[X][Y + 1] == 1) {
        cabbage(X, Y + 1);
    }

    if (0 <= X - 1 && field[X - 1][Y] == 1) {
        cabbage(X - 1, Y);
    }

    if (0 <= Y - 1 && field[X][Y - 1] == 1) {
        cabbage(X, Y - 1);
    }

    return 0;
}