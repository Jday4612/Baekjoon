#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    long long int a, b, tmp = 1;
    
    scanf("%lld %lld", &a, &b);

    for (int j = 1; j <= a && j <= b; j++) {
        if (a % j == 0 && b % j == 0) {
            tmp = a * b / j;
        }
    }
    printf("%lld", tmp);

    return 0;
}