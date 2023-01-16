#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, M;
	int a[100][100], b[100][100];

	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &a[i][j]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &b[i][j]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d ", a[i][j] + b[i][j]);
		printf("\n");
	}

	return 0;
}