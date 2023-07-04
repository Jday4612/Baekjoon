#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int T, N, a[1000001], ans;

    for (int i = 2; i < 1000001; i++) {
        a[i] = i;
    }

    for (int i = 2; i < 1000001; i++) {
        for (int j = 2; j < 1000001; j++) {
            if (i * j > 1000000) {
                break;
            }
            a[i * j] = 0;
        }
    }

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);

        ans = 0;
        for (int j = 2; j < N; j++) {
            if (a[N - j] + a[j] == N) {
                ans++;
                if (N - j == j) {
                    ans++;
                }
            }
        }
        printf("%d\n", ans / 2);
    }

    return 0;
}