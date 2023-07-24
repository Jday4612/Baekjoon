#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, check;

    for (int i = 1; i < 9; i++) {
        scanf("%d", &n);

        if (i == 1) {
            check = n == 1 ? 1 : 0;
        }

        if (check == 1 && n == i) {
            if (i == 8) {
                printf("ascending");
            }
        }
        else if (check == 0 && n == 9 - i) {
            if (i == 8) {
                printf("descending");
            }
        }
        else {
            printf("mixed");
            break;
        }
    }

    return 0;
}