#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char N[30];
    int B, len, ans = 0;

    scanf("%s %d", N, &B);
    len = (int)strlen(N);

    for (int i = len - 1; i >= 0; i--) {
        if ('0' <= N[i] && N[i] <= '9') {
            ans += pow(B, len - 1 - i) * (int)(N[i] - '0');
        }
        else {
            ans += pow(B, len - 1 - i) * (int)(N[i] - 'A' + 10);
        }
    }

    printf("%d", ans);

    return 0;
}