#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, v;
	int a[100];
	int cnt = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	scanf("%d", &v);

	for (int i = 0; i < N; i++) {
		if (a[i] == v)
			cnt++;
	}

	printf("%d", cnt);

	return 0;
}