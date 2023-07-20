#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, arr[100000], stack[100000], idx = 0, stack_idx = -1, ans_idx = 0, num = 1;
    char ans[200000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        //push
        if (stack_idx == -1 || stack[stack_idx] < arr[idx]) {
            stack[++stack_idx] = num++;
            ans[ans_idx++] = '+';
        }
        else if (stack[stack_idx] == arr[idx]) {
            stack_idx--;
            ans[ans_idx++] = '-';
            idx++;
        }
        else {
            printf("NO");
            break;
        }

        if (idx == n) {
            for (int j = 0; j < ans_idx; j++) {
                printf("%c\n", ans[j]);
            }
            break;
        }
    }

    return 0;
}