#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char ans[30];
    int B, N;

    scanf("%d %d", &N, &B);

    int i = 0;
    while (N) {
        if (0 <= N % B && N % B <= 9) {
            ans[i++] = N % B + '0';
        }
        else {
            ans[i++] = N % B - 10 + 'A';
        }

        N /= B;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", ans[j]);
    }

    return 0;
}