#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char n[10];
	scanf("%s", n);

	for (int i = 0; i < strlen(n); i++) {
		for (int j = 0; j < strlen(n) - 1; j++) {
			if (n[j] < n[j + 1]) {
				char tmp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = tmp;
			}
		}
	}

	printf("%s", n);

	return 0;
}