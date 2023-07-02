#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a1, a2, b1, b2, x, y;

    scanf("%d %d", &a1, &b1);
    scanf("%d %d", &a2, &b2);

    x = b1 == b2 ? a1 + a2 :(a1 * b2) + (a2 * b1);
    y = b1 == b2 ? b1 : b1 * b2;

    int i = 2;
    while (i <= x && i <= y) {
        if (x % i != 0 || y % i != 0) {
            i++;
        }
        else {
            x /= i;
            y /= i;
        }
    }
    
    printf("%d %d", x, y);

    return 0;
}