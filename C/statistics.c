#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b);
int x[500000];

int main() {
	int N, cnt[8001] = { 0 };
	double sum = 0;
	int mean = 0, med = 0, mode = 0, range = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x[i]);
		sum += x[i];
		cnt[x[i] + 4000]++;
	}

	qsort(x, N, sizeof(int), compare);

	mean = round(sum / N);
	med = x[N / 2];

	int max = 0, tmp = 0;
	for (int j = 0; j < 8001; j++) {
		if (cnt[j] > max) {
			max = cnt[j];
			mode = j - 4000;
			tmp = 1;
		}
		else if (cnt[j] == max) {
			tmp++;

			if (tmp == 2)
				mode = j - 4000;
		}
	}

	range = x[N - 1] - x[0];

	printf("%d\n%d\n%d\n%d", mean, med, mode, range);

	return 0;
}

int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}