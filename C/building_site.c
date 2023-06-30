#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, x1 = 10000, x2 = -10000, y1 = 10000, y2 = -10000, a, b;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);

        if (x1 > a) {
            x1 = a;
        }
        if (x2 < a) {
            x2 = a;
        }
        if (y1 > b) {
            y1 = b;
        }
        if (y2 < b) {
            y2 = b;
        }
    }

    if (N == 1) {
        printf("0");
    }
    else {
        printf("%d", (x2 - x1) * (y2 - y1));
    }

    return 0;
}