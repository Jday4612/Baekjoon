#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    
    printf("%d %d", (e * c - b * f) / (a * e - b * d), (d * c - a * f) / (d * b - a * e));

    return 0;
}