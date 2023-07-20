#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int left_p, left_g, len, len_left, check;

    while (1) {
        char str[100], left[100];
        scanf("%[^\n]s", str);

        if (str[0] == '.') {
            break;
        }

        len = (int)strlen(str);
        len_left = -1;
        check = 1;
        left_p = 0;
        left_g = 0;

        for (int i = 0; i < len; i++) {
            if (str[i] == '(') {
                left_p++;
                left[++len_left] = '(';
            }
            else if (str[i] == ')') {
                if (left_p && left[len_left] == '(') {
                    len_left--;
                    left_p--;
                }
                else {
                    check = 0;
                    break;
                }
            }
            else if (str[i] == '[') {
                left_g++;
                left[++len_left] = '[';
            }
            else if (str[i] == ']') {
                if (left_g && left[len_left] == '[') {
                    len_left--;
                    left_g--;
                }
                else {
                    check = 0;
                    break;
                }
            }
        }

        if (left_p == 0 && left_g == 0 && check) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }

        getchar();
    }

    return 0;
}