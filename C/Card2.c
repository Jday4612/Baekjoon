#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, arr[500001], j = 0, k = 1, l;

    scanf("%d", &N);
    l = N;

    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }

    if (N == 1) {
        j = 2;
    }
    else {
        while (l > 1) {
            arr[k++] = 0;
            l--;

            k = k > N ? 0 : k;

            arr[j++] = arr[k];
            arr[k++] = 0;

            k = k > N ? 0 : k;
            j = j > N ? 0 : j;
        }
    }

    printf("%d", arr[j - 1]);

    return 0;
}