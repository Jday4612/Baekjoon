#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int X, N, a, b;
	int tmp = 0;

	scanf("%d", &X);
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		scanf("%d", &b);

		tmp += a * b;
	}

	if (X == tmp)
		printf("Yes");
	else
		printf("No");

	return 0;
}