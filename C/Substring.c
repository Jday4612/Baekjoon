#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char w[1001];
} string;

int compare(const void* a, const void* b);
string sub[500501];

int main() {
    char S[1001];
    int len, cnt = 0, tmp = 0, ans = 0;

    scanf("%s", &S);
    len = (int)strlen(S);

    for (int i = 0; i < len; i++) {
        tmp = 0;

        while (tmp < len - i) {
            strncpy(sub[cnt].w, S + i, tmp + 1);
            cnt++;
            tmp++;
        }
    }

    qsort(sub, cnt, sizeof(string), compare);

    for (int i = 0; i < cnt; i++) {
        if (strcmp(sub[i].w, sub[i + 1].w) != 0)
            ans++;
    }

    printf("%d", ans);

    return 0;
}

int compare(const void* a, const void* b) {
    return strcmp((char*)a, (char*)b);
}