#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int GCD(int a, int b);
int LCM(int a, int b);

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n%d", GCD(a, b), LCM(a, b));

    return 0;
}

int GCD(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    
    return GCD(b, a % b);
}

int LCM(int a, int b) {
    int t;

    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            t = a * b / i;
        }
    }
    
    return t;
}