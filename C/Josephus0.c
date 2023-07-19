#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, K, arr[1000], t, z, cnt;

    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    printf("<%d", arr[K - 1]);
    arr[K - 1] = 0;

    t = K;
    for (int j = 0; j < N - 1; j++) {
        cnt = 0;
        z = -1;

        while (cnt < K) {
            z++;

            if (arr[(t + z) % N] != 0) {
                cnt++;
            }
        }

        t = (t + z) % N;
        printf(", %d", arr[t]);
        arr[t] = 0;
    }
    printf(">");

    return 0;
}