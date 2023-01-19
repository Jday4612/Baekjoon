#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* tmp;
int K, num = -1, cnt = 0;

void merge_sort(int* A, int p, int r);
void merge(int* A, int p, int q, int r);

int main() {
    int N;
    int* A;
    scanf("%d %d", &N, &K);
    A = malloc(sizeof(int) * N);
    tmp = malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    merge_sort(A, 0, N - 1);

    printf("%d", num);
}

void merge_sort(int* A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void merge(int* A, int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int t = 0;

    while (i <= q && j <= r) {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }

    while (i <= q)
        tmp[t++] = A[i++];

    while (j <= r)
        tmp[t++] = A[j++];

    i = p;
    t = 0;
    while (i <= r) {
        A[i++] = tmp[t++];
        cnt++;

        if (cnt == K) {
            num = A[i - 1];
            break;
        }
    }
}