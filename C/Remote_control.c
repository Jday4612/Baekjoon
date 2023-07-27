#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int button[10] = { 0 };
int check(int a);

int main() {
    int N, M, tmp, min, len;

    scanf("%d", &N);
    scanf("%d", &M);

    min = abs(N - 100);

    for (int i = 0; i < M; i++) {
        scanf("%d", &tmp);
        button[tmp] = 1;
    }

    for (int j = 0; j < 1000000; j++) {
        len = check(j);

        if (len > 0) {
            tmp = len + abs(N - j);
            min = min < tmp ? min : tmp;
        }
    }
    printf("%d", min);

    return 0;
}

int check(int a) {

    if (a == 0) {
        return button[a] ? 0 : 1;
    }

    int len = 0;

    while (a > 0) {
        if (button[a % 10]) {
            return 0;
        }

        a /= 10;
        len++;
    }

    return len;
}