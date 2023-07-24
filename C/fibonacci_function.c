#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int T, N, fibo[41] = { 0, 1 };

    for (int i = 2; i < 41; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        
        if (N == 0) {
            printf("1 0\n");
        }
        else {
            printf("%d %d\n", fibo[N - 1], fibo[N]);
        }
    }

    return 0;
}