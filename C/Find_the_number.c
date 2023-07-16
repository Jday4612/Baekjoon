#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
int search(int arr[], int num, int start, int end);

int main() {
    int N, M, arrN[100000], arrM[100000];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arrN[i]);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &arrM[i]);
    }

    qsort(arrN, N, sizeof(int), compare);

    for (int j = 0; j < M; j++) {
        printf("%d\n", search(arrN, arrM[j], 0, N - 1));
    }

    return 0;
}

int compare(const void* a, const void* b) {
	return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int search(int arr[], int num, int start, int end) {
    if (end < start) {
        return 0;
    }

    int middle = (start + end) / 2;

    if (num == arr[middle]) {
        return 1;
    }
    else if (num < arr[middle]) {
        search(arr, num, start, middle - 1);
    }
    else {
        search(arr, num, middle + 1, end);
    }
}