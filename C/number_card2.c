#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
int lower_bound(int* arr, int N, int num);
int upper_bound(int* arr, int N, int num);

int a[500000], b[500000];

int main() {
    int N, M, l, u;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
        scanf("%d", &b[i]);

    qsort(a, N, sizeof(int), compare);

    for (int i = 0; i < M; i++) {
        l = lower_bound(a, N, b[i]);
        u = upper_bound(a, N, b[i]);
        printf("%d ", u - l);
    }

    return 0;
}

int compare(const void* a, const void* b) {
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

int lower_bound(int* arr, int N, int num) {
    int start = 0;
    int end = N;
    int mid = (start + end) / 2;

    while (start < end) {
        if (num <= arr[mid])
            end = mid;
        else
            start = mid + 1;

        mid = (start + end) / 2;
    }

    return end;
}

int upper_bound(int* arr, int N, int num) {
    int start = 0;
    int end = N;
    int mid = (start + end) / 2;

    while (start < end) {
        if (num < arr[mid])
            end = mid;
        else
            start = mid + 1;

        mid = (start + end) / 2;
    }

    return end;
}