#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, ans = 1;

    scanf("%d", &N);
    for (int i = 2; i * i < N + 1; i++) {
        ans++;
    }

    printf("%d", ans);

    return 0;
}