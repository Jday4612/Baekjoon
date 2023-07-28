#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, M, tmp1, tmp2, friend[101][101] = { 0 }, person = 0, cnt = 100;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        friend[tmp1][tmp2] = 1;
        friend[tmp2][tmp1] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (j == k) {
                    continue;
                }
                else if (friend[j][i] != 0 && friend[i][k] != 0) {
                    if (friend[j][k] == 0) {
                        friend[j][k] = friend[j][i] + friend[i][k];
                    }
                    else {
                        friend[j][k] = friend[j][k] < friend[j][i] + friend[i][k] ? friend[j][k] : friend[j][i] + friend[i][k];
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        tmp1 = 0;
        
        for (int j = 1; j <= N; j++) {
            tmp1 += friend[i][j];
        }

        if (tmp1 < cnt) {
            cnt = tmp1;
            person = i;
        }
    }

    printf("%d", person);

    return 0;
}