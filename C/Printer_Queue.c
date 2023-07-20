#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int t, N, M, arr[100], idx, max, cnt;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &N, &M);

        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[j]);
        }

        cnt = 1;
        idx = 0;
        while (1) {
            max = 0;
            for (int k = 0; k < N; k++) {
                if (max < arr[k]) {
                    max = arr[k];
                }
            }

            while (max != arr[idx]) {
                idx = (idx + 1) % N;
            }

            if (idx == M) {
                break;
            }

            arr[idx] = 0;
            idx = (idx + 1) % N;
            cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}