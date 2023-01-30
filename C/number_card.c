#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
int binary_search(int* arr, int N, int num);

int a[500000], b[500000];

int main() {
    int N, M;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
        scanf("%d", &b[i]);

    qsort(a, N, sizeof(int), compare);

    for (int i = 0; i < M; i++) {
        if (binary_search(a, N, b[i]))
            printf("1 ");
        else
            printf("0 ");
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

int binary_search(int* arr, int N, int num) {
    int start = 0;
    int end = N;
    int mid = (start + end) / 2;

    while (start <= end) {
        if (arr[mid] == num)
            return 1;
        else if (arr[mid] < num)
            start = mid + 1;
        else
            end = mid - 1;

        mid = (start + end) / 2;
    }

    return 0;
}