#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, k, i = 1, j = 0;
    scanf("%d %d", &N, &k);

    while (i <= N) {
        if (N % i == 0) {
            j++;
        }

        if (j == k) {
            printf("%d", i);
            break;
        }
        i++;
    }

    if (i - 1 == N && j < k) {
        printf("0");
    }

    return 0;
}