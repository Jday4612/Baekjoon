#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int coin[4] = { 25, 10, 5, 1 };
    int T, C;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &C);

        for (int j = 0; j < 4; j++) {
            printf("%d ", C / coin[j]);
            C %= coin[j];
        }
        printf("\n");
    }

    return 0;
}