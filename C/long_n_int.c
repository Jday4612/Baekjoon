#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N > 0) {
        N -= 4;
        printf("long ");
    }
    
    printf("int");

    return 0;
}