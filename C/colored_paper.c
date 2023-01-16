#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[100][100] = { 0 };
	int c, x, y, cnt = 0;

	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		scanf("%d %d", &x, &y);

		for (int j = x - 1; j < x + 9; j++) {
			for (int k = y - 1; k < y + 9; k++)
				a[j][k] = 1;
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (a[i][j] == 1)
				cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}