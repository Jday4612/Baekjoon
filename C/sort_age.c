#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int j;
	int age;
	char name[101];
} member;

int compare(const void* a, const void* b);

member m[100000];

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %s", &m[i].age, &m[i].name);
		m[i].j = i;
	}

	qsort(m, N, sizeof(member), compare);

	for (int i = 0; i < N; i++)
		printf("%d %s\n", m[i].age, m[i].name);
	return 0;
}

int compare(const void* a, const void* b) {
	member* A = (member*)a;
	member* B = (member*)b;

	if (A->age > B->age || (A->age == B->age && A->j > B->j))
		return 1;
	else
		return 0;
}