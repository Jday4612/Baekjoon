#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, tmp, cnt = 0;
	int a[10000] = { 0 };

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		a[tmp - 1]++;
	}

	for (int j = 0; j < 10000; j++) {
		if (a[j] > 0) {
			for (int k = 0; k < a[j]; k++) {
				printf("%d\n", j + 1);
				cnt++;
			}
		}

		if (cnt == N)
			break;
	}

	return 0;
}