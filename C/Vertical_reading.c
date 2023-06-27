#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char T[5][16] = {0, };

    for (int i = 0; i < 5; i++) {
        scanf("%s", T[i]);
    }

    for (int j = 0; j < 15; j++) {
        for (int k = 0; k < 5; k++) {
            if (T[k][j] == '\0') {
                continue;
            }
            printf("%c", T[k][j]);
        }
    }

    return 0;
}