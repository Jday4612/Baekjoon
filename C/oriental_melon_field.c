#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int K, x = 1, y = 1;
    int a[6][2], dir[4] = {0, };

    scanf("%d", &K);
    for (int i = 0; i < 6; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        dir[a[i][0] - 1]++;
    }

    for (int j = 0; j < 6; j++) {
        if (dir[a[j][0] - 1] == 1)
            x *= a[j][1];
        else if (a[j][0] == a[(j + 2) % 6][0])
            y *= a[(j + 1) % 6][1];
    }

    printf("%d", (x - y) * K);

    return 0;
}