#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int N;
	int x[100000], y[100000];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &x[i], &y[i]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (x[j] > x[j + 1] || (x[j] == x[j + 1] && y[j] > y[j + 1])) {
				int tmp1 = x[j];
				int tmp2 = y[j];

				x[j] = x[j + 1];
				y[j] = y[j + 1];
				x[j + 1] = tmp1;
				y[j + 1] = tmp2;
			}
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d %d\n", x[i], y[i]);

	return 0;
}