#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    while (a != 0 && b != 0 && c != 0) {
        if (a >= b + c || b >= a + c || c >= a + b) {
            printf("Invalid\n");
        }
        else {
            if (a == b && b == c && c == a) {
                printf("Equilateral\n");
            }
            else if (a == b || b == c || c == a) {
                printf("Isosceles\n");
            }
            else if (a != b || b != c || c != a) {
                printf("Scalene\n");
            }
        }

        scanf("%d %d %d", &a, &b, &c);
    }

    return 0;
}