#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, a[1000], tmp;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d\n", a[i]);

	return 0;
}