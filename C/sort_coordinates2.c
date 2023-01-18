#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} coord;

int compare(const void* a, const void* b);

int main() {
	int N;
	coord c[100000];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &c[i].x, &c[i].y);

	qsort(c, N, sizeof(coord), compare);

	for (int i = 0; i < N; i++)
		printf("%d %d\n", c[i].x, c[i].y);

	return 0;
}

int compare(const void* a, const void* b) {
	coord* A = (coord*)a;
	coord* B = (coord*)b;

	if (A->y > B->y)
		return 1;
	else if (A->y == B->y) {
		if (A->x > B->x)
			return 1;
		else
			return -1;
	}
	else
		return 0;
}