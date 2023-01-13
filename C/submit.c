#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, n[30];

	for (int i = 0; i < 28; i++) {
		scanf("%d", &a);
		n[a - 1] = 1;
	}

	for (int j = 0; j < 30; j++) {
		if (n[j] != 1)
			printf("%d\n", j + 1);
	}

	return 0;
}