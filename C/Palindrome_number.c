#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int t, i, check, arr[5] = { 0 };
    
    while (1) {
        scanf("%d", &t);

        if (t == 0) {
            break;
        }

        for (i = 0; t != 0; i++) {
            arr[i] = t % 10;
            t /= 10;
        }

        check = 1;
        for (int j = 0; j < i / 2; j++) {
            if (arr[j] != arr[i - 1 - j]) {
                check = 0;
                break;
            }
        }

        if (check) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }

    return 0;
}