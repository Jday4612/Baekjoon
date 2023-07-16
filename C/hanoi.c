#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void hanoi(int n, int start, int middle, int end);

int main() {
    int k, cnt = 0;
    scanf("%d", &k);

    cnt = pow(2, k) - 1;
    printf("%d\n", cnt);
    hanoi(k, 1, 2, 3);

    return 0;
}

void hanoi(int n, int start, int middle, int end) {
    if (n == 1) {
        printf("%d %d\n", start, end);
    }
    else {
        hanoi(n - 1, start, end, middle);
        printf("%d %d\n", start, end);
        hanoi(n - 1, middle, start, end);
    }
}