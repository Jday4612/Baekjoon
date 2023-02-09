#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
int A[400000];

int main() {
    int N, M, cnt = 0;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N + M; i++)
        scanf("%d", &A[i]);
    
    qsort(A, N + M, sizeof(int), compare);

    for (int i = 0; i < N + M; i++) {
        if (A[i] == A[i + 1])
            cnt += 2;
    }

    printf("%d", N + M - cnt);
}

int compare(const void* a, const void* b) {
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}