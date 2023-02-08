#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char n[21];
} person;

person p[1000000], unnamed[500000];
int compare(const void* a, const void* b);

int main() {
    int N, M, cnt = 0;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N + M; i++)
        scanf("%s", p[i].n);

    qsort(p, N + M, sizeof(person), compare);

    for (int i = 0; i < N + M; i++) {
        if (strcmp(p[i].n, p[i + 1].n) == 0)
            unnamed[cnt++] = p[i];
    }

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%s\n", unnamed[i].n);
}

int compare(const void* a, const void* b) {
    person* A = (person*)a;
    person* B = (person*)b;

    return strcmp(A->n, B->n);
}