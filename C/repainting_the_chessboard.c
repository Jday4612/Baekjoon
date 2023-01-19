#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, M, cntB, cntW, cnt = 64;
    char board[50][50];

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%s", &board[i]);

    for (int i = 0; i + 7 < N; i++) {
        for (int j = 0; j + 7 < M; j++) {
            cntB = 0;
            cntW = 0;

            for (int k = i; k < i + 8; k++) {
                for (int l = j; l < j + 8; l++) {
                    if ((k + l) % 2 == 0) {
                        if (board[k][l] == 'B')
                            cntW++;
                        else
                            cntB++;
                    }
                    else {
                        if (board[k][l] == 'B')
                            cntB++;
                        else
                            cntW++;
                    }
                }
            }
            if (cnt > cntB)
                cnt = cntB;
            
            if (cnt > cntW)
                cnt = cntW;
        }
    }

    printf("%d", cnt);

    return 0;
}