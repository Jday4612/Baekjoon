#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int L;
    long long ans = 0, r = 1;
    char arr[51];

    scanf("%d", &L);
    scanf("%s", arr);

    for (int i = 0; i < L; i++) {
        ans = (ans + (arr[i] -'a' + 1) * r) % 1234567891;
        r = r * 31 % 1234567891;
    }
    printf("%lld", ans);

    return 0;
}