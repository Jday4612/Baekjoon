#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, M, i, j, k;
    int basket[100] = { 0, };
    scanf("%d %d", &N, &M);

    for (int a = 0; a < M; a++) {
        scanf("%d %d %d", &i, &j, &k);

        for (int b = i - 1; b < j; b++)
            basket[b] = k;
    }

    for (int z = 0; z < N; z++)
        printf("%d ", basket[z]);

    return 0;
}