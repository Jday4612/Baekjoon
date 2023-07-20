#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, cnt = 0;

    scanf("%d", &N);

    cnt = N / 5 + N / 25 + N / 125;

    printf("%d", cnt);

    return 0;
}