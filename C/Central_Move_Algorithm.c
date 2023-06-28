#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    int N, k = 3;
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        k += pow(2, i + 1);
    }

    printf("%d", k * k);

    return 0;
}