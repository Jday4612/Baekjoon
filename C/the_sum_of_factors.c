#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;

    while (1) {
        scanf("%d", &N);

        if (N == -1) {
            break;
        }
        else {
            int i = 1, tmp = 0, len = 0;
            int ans[100000];

            while (i < N) {
                if (N % i == 0) {
                    ans[len++] = i;
                    tmp += i;
                }
                i++;
            }

            if (tmp == N) {
                printf("%d = ", N);

                for (int j = 0; j < len - 1; j++) {
                    printf("%d + ", ans[j]);
                }

                printf("%d", ans[len - 1]);
            }
            else {
                printf("%d is NOT perfect.", N);
            }
        }
        printf("\n");
    }

    return 0;
}