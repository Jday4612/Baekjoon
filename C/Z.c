#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int Z(int N, int r, int c);

int main() {
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
    printf("%d", Z(N, r, c));

    return 0;
}

int Z(int N, int r, int c) {
    if (N < 1) {
        return 0;
    }

    int mid = pow(2, N - 1);

    if (r < mid && c < mid) {
        return Z(N - 1, r, c);
    }
    else if (r < mid && c >= mid) {
        return mid * mid + Z(N - 1, r, c - mid);
    }
    else if (r >= mid && c < mid) {
        return mid * mid * 2 + Z(N - 1, r - mid, c);
    }
    else if (r >= mid && c >= mid) {
        return mid * mid * 3 + Z(N - 1, r - mid, c - mid);
    }

    return 0;
}