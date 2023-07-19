#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, arr[10000], len = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char check[6];
        scanf("%s", check);

        if (check[0] == 'p' && check[1] == 'u') {
            scanf("%d", &arr[len]);
            len++;
        }
        else if (check[0] == 'p' && check[1] == 'o') {
            if (len == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", arr[0]);
                for (int j = 0; j < len - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                len--;
            }
        }
        else if (check[0] == 's') {
            printf("%d\n", len);
        }
        else if (check[0] == 'e') {
            if (len) {
                printf("0\n");
            }
            else {
                printf("1\n");
            }
        }
        else if (check[0] == 'f') {
            if (len == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", arr[0]);
            }
        }
        else { //back
            if (len == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", arr[len - 1]);
            }
        }
    }

    return 0;
}