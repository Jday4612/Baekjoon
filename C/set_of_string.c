#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char w[501];
} word;

word a[10000];

int compare(const void* a, const void* b);
int binary_search(word* arr, int N, char* s);

int main() {
    int N, M, cnt = 0;
    char b[501];
    
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++)
        scanf("%s", a[i].w);

    qsort(a, N, sizeof(word), compare);

    for (int j = 0; j < M; j++) {
        scanf("%s", b);

        cnt += binary_search(a, N, b);
    }

    printf("%d", cnt);

    return 0;
}

int compare(const void* a, const void* b) {
    word* A = (word*)a;
    word* B = (word*)b;

    return strcmp(A->w, B->w);
}

int binary_search(word* arr, int N, char* s) {
    int start = 0;
    int end = N;
    int mid = (start + end) / 2;

    while (start <= end) {
        if (strcmp(arr[mid].w, s) == 0)
            return 1;
        else if (strcmp(arr[mid].w, s) < 0)
            start = mid + 1;
        else
            end = mid - 1;

        mid = (start + end) / 2;
    }

    return 0;
}