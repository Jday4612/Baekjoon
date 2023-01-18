#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n;
	int order;
} coord;

coord a[1000000];
int b[1000000];

int compare(const void* a, const void* b);

int main() {
	int N, tmp = 0, min;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i].n);
		a[i].order = i;
	}

	qsort(a, N, sizeof(coord), compare);

	min = a[0].n;
	for (int i = 0; i < N; i++) {
		if (min != a[i].n) {
			min = a[i].n;
			tmp++;
		}
		b[a[i].order] = tmp;
	}

	for (int i = 0; i < N; i++)
		printf("%d ", b[i]);

	return 0;
}

int compare(const void* a, const void* b) {
	coord* A = (coord*) a;
	coord* B = (coord*)b;
	
	if (A->n > B->n)
		return 1;
	else if (A->n < B->n)
		return -1;
	else
		return 0;
}