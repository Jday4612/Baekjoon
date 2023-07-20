#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int K, N, arr[10000], cnt;
    long long ans = 1, left = 1, mid, right = 0;
    scanf("%d %d", &K, &N);

    for (int i = 0; i < K; i++) {
        scanf("%d", &arr[i]);

        if (right < arr[i]) {
            right = arr[i];
        }
    }

    while (left <= right) {
        cnt = 0;
        mid = (left + right) / 2;

        for (int i = 0; i < K; i++) {
            cnt += arr[i] / mid;
        }

        if (cnt >= N) {
            left = mid + 1;
            
            if (mid > ans) {
                ans = mid;
            }
        }
        else {
            right = mid - 1;
        }
    }

    printf("%lld", ans);

    return 0;
}