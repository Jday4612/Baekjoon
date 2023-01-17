#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[5];

	for (int i = 0; i < 5; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}

	printf("%d\n%d", (a[0] + a[1] + a[2] + a[3] + a[4]) / 5, a[2]);

	return 0;
}