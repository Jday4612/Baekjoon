#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, k, x[1000];

	scanf("%d %d", &N, &k);

	for (int i = 0; i < N; i++)
		scanf("%d", &x[i]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (x[j] > x[j + 1]) {
				int tmp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = tmp;
			}
		}
	}

	printf("%d", x[N - k]);

	return 0;
}