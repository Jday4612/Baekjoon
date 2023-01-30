#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char p[21];
    int num;
} pokemon;

pokemon a[100000];
pokemon z[100000];
char b[100000];

int compare(const void* a, const void* b);
int binary_search(pokemon* arr, int N, char* s);

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", a[i].p);
        a[i].num = z[i].num = i + 1;
        z[i] = a[i];
    }

    qsort(a, N, sizeof(pokemon), compare);

    for (int j = 0; j < M; j++) {
        scanf("%s", &b);

        if ('0' <= b[0] && b[0] <= '9')
            printf("%s\n", z[atoi(b) - 1].p);
        else
            printf("%d\n", a[binary_search(a, N, b)].num);
    }

    return 0;
}

int compare(const void* a, const void* b) {
    pokemon* A = (pokemon*)a;
    pokemon* B = (pokemon*)b;

    return strcmp(A->p, B->p);
}

int binary_search(pokemon* arr, int N, char* s) {
    int start = 0;
    int end = N;
    int mid = (start + end) / 2;

    while (start <= end) {
        if (strcmp(arr[mid].p, s) == 0)
            return mid;
        else if (strcmp(arr[mid].p, s) < 0)
            start = mid + 1;
        else
            end = mid - 1;

        mid = (start + end) / 2;
    }

    return 0;
}