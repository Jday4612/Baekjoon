#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b);

int main() {
    int N, list[100000], max = 0, tmp;

    scanf("%d", &N);
    scanf("%d", &list[0]);

    for (int i = 1; i < N; i++) {
        scanf("%d", &list[i]);
        list[i] -= list[0];
        max = list[i] > max ? list[i] : max;
    }

    tmp = gcd(list[1], list[2]);
    for (int j = 3; j < N; j++) {
        tmp = gcd(list[j], tmp);
    }

    printf("%d", max / tmp - N + 1);

    return 0;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}