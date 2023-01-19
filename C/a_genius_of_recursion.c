#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char w[1001];
} word;

int tmp;

int recursion(const char* s, int l, int r) {
    tmp++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int T, n;
    word S[1000];

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
        scanf("%s", S[i].w);

    for (int i = 0; i < T; i++) {
        tmp = 0;
        n = isPalindrome(S[i].w);
        printf("%d %d\n", n, tmp);
    }
}