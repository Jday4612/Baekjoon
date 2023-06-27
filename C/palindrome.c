#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char t[100];
    int n;

    scanf("%s", t);
    n = (int)strlen(t);

    for (int i = 0; i < (n + 1) / 2; i++) {
        if (t[i] != t[n - 1 - i]) {
            printf("0");
            break;
        }

        if (i == (n + 1) / 2 - 1) {
            printf("1");
        }
    }

    return 0;
}