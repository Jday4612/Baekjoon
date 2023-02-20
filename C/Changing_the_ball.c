#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, M, i, j, tmp;
    int basket[100];
    scanf("%d %d", &N, &M);

    for (int a = 0; a < N; a++)
        basket[a] = a + 1;

    for (int b = 0; b < M; b++) {
        scanf("%d %d", &i, &j);

        tmp = basket[i - 1];
        basket[i - 1] = basket[j - 1];
        basket[j - 1] = tmp;
    }

    for (int z = 0; z < N; z++)
        printf("%d ", basket[z]);

    return 0;
}