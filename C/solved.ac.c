#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main() {
    int n, t[300001], z, ans = 0;

    scanf("%d", &n);

    if (n == 0) {
        printf("0");
    }
    else {
        z = (int)(n * 0.15 + 0.5);

        for (int i = 0; i < n; i++) {
            scanf("%d", &t[i]);
        }

        qsort(t, n, sizeof(int), compare);

        for (int j = z; j < n - z; j++) {
            ans += t[j];
        }

        ans = (int)((double)ans / (n - 2 * z) + 0.5);
        printf("%d", ans);
    }

    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}