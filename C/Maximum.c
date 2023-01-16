#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[9][9];
	int max = 0;
	int x, y;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			scanf("%d", &a[i][j]);
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (a[i][j] >= max) {
				max = a[i][j];
				x = i + 1;
				y = j + 1;
			}

			if (max == 99)
				break;
		}
	}

	printf("%d\n%d %d", max, x, y);

	return 0;
}