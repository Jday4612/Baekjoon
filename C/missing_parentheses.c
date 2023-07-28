#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, m;
    char mark;

    int i = 0;
    for (scanf("%d", &n); scanf("%c", &mark), mark != 10;) {
        if (mark == '-') {
            i = 1;
        }

        scanf("%d", &m);

        if (i == 1) {
            n -= m;
        }
        else {
            n += m;
        }
    }
    printf("%d", n);

    return 0;
}