#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int K, len = 0, ans = 0, arr[100000];

    scanf("%d", &K);

    for (int i = 0; i < K; i++) {
        scanf("%d", &arr[len]);
        
        if (arr[len] == 0) {
            len--;
        }
        else {
            len++;
        }
    }

    for (int j = 0; j < len; j++) {
        ans += arr[j];
    }

    printf("%d", ans);

    return 0;
}