#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, K, tmp = 1;

    scanf("%d %d", &N, &K);
    
    for (int i = N; i > K; i--) {
        tmp *= i;
    }

    for (int j = 1; j <= N - K; j++) {
        tmp /= j;
    }

    printf("%d", tmp);

    return 0;
}