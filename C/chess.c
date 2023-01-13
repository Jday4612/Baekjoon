#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int king, queen, rook, bishop, knight, pawn;

	scanf("%d", &king);
	scanf("%d", &queen);
	scanf("%d", &rook);
	scanf("%d", &bishop);
	scanf("%d", &knight);
	scanf("%d", &pawn);

	printf("%d %d %d %d %d %d", 1 - king, 1 - queen, 2 - rook, 2 - bishop, 2 - knight, 8 - pawn);

	return 0;
}