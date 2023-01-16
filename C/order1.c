#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[1000000], list[1000000];

void merge_sort(int start, int end);
void merge(int start, int mid, int end);

int main() {
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	merge_sort(0, N - 1);

	for (int j = 0; j < N; j++)
		printf("%d\n", a[j]);

	return 0;
}

void merge_sort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}
}

void merge(int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;
	
	while (i <= mid && j <= end) {
		if (a[i] <= a[j])
			list[k++] = a[i++];
		else
			list[k++] = a[j++];
	}

	if (i > mid) {
		for (int l = j; l <= end; l++)
			list[k++] = a[l];
	}
	else {
		for (int m = i; m <= mid; m++)
			list[k++] = a[m];
	}

	for (int t = start; t <= end; t++)
		a[t] = list[t];
}