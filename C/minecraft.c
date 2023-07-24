#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, M, B, g[501][501], min = 257, max = -1, tmp1, tmp2, time, height = 0;

    scanf("%d %d %d", &N, &M, &B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &g[i][j]);

            if (g[i][j] < min) {
                min = g[i][j];
            }

            if (max < g[i][j]) {
                max = g[i][j];
            }
        }
    }

    if (min == max) {
        printf("0 %d", max);
    }
    else {
        time = N * M * 256;

        while (min <= max) {
            tmp1 = 0;
            tmp2 = 0;

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (g[i][j] < max) {
                        tmp1 += max - g[i][j];
                    }
                    else if (max < g[i][j]) {
                        tmp2 += g[i][j] - max;
                    }
                }
            }

            if (tmp1 <= B + tmp2 && tmp1 + tmp2 * 2 < time) {
                time = tmp1 + tmp2 * 2;
                height = max;
            }
            max--;
        }

        printf("%d %d", time, height);
    }

    return 0;
}