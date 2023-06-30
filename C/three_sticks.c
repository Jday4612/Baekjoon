#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (b > a && b > c) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    else if (c > a && c > b) {
        int tmp = a;
        a = c;
        c = tmp;
    }

    while (1) {
        if (a < b + c) {
            printf("%d", a + b + c);
            break;
        }
        a--;
    }

    return 0;
}