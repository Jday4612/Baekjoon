#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int T;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char arr[50];
        int len, L = 0, R = 0, check = 1;

        scanf("%s", arr);
        len = (int)strlen(arr);

        for (int j = 0; j < len; j++) {
            if (arr[j] == '(') {
                L++;
            }
            else {
                R++;
            }

            if (L > 0 && R > 0) {
                L--;
                R--;
            }

            if ((L == 0 && R > 0) || (j == len - 1 && L > 0)) {
                check = 0;
                break;
            }
        }
        
        if (check) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}