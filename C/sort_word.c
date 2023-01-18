#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int len;
	char w[50];
} word;

int compare(const void* a, const void* b);

word list[20000];

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &list[i].w);
		list[i].len = strlen(list[i].w);
	}

	qsort(list, N, sizeof(word), compare);

	for (int i = 0; i < N; i++) {
		if (strcmp(list[i].w, list[i + 1].w))
			printf("%s\n", list[i].w);
	}
	return 0;
}

int compare(const void* a, const void* b) {
	word* A = (word*)a;
	word* B = (word*)b;

	if (A->len > B->len)
		return 1;
	else if (A->len == B->len)
		return strcmp(A->w, B->w);
	else
		return 0;
}