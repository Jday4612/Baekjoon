#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check(int x1, int y1, int x2, int y2, int r);

int main() {
    int T, n, cX, cY, r, cnt;
    int x[2], y[2];

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        cnt = 0;
        for (int j = 0; j < 2; j++)
            scanf("%d %d", &x[j], &y[j]);

        scanf("%d", &n);
        for (int k = 0; k < n; k++) {
            scanf("%d %d %d", &cX, &cY, &r);

            if (check(x[0], y[0], cX, cY, r) != check(x[1], y[1], cX, cY, r))
                cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}

int check(int x1, int y1, int x2, int y2, int r) {
    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > r * r)
        return 0;
    else
        return 1;
}