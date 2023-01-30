#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    int N, m = 665, cnt = 0;

    scanf("%d", &N);

    while (1) {
        if (cnt == N)
            break;
        
        m++;

        for (int i = 0; i < 10; i++) {
            if (m / (int)pow(10, i) % 1000 == 666) {
                cnt++;
                break;
            }
        }
    }

    printf("%d", m);

    return 0;
}