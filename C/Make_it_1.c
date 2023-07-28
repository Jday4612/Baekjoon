#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, tmp, num[1000001];
    scanf("%d", &N);

    num[1] = 0;
    for (int i = 2; i <= N; i++) {
        tmp = num[i - 1] + 1;

        if (i % 3 == 0) {
            tmp = tmp < num[i / 3] + 1 ? tmp : num[i / 3] + 1;
        }

        if (i % 2 == 0) {
            tmp = tmp < num[i / 2] + 1 ? tmp : num[i / 2] + 1;
        }

        num[i] = tmp;
    }
    printf("%d", num[N]);

    return 0;
}