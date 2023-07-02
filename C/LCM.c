#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int T, a, b, tmp = 1;
    
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &a, &b);

        for (int j = 1; j <= a && j <= b; j++) {
            if (a % j == 0 && b % j == 0) {
                tmp = a * b / j;
            }
        }
        printf("%d\n", tmp);
    }

    return 0;
}