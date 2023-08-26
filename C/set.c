#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int M, num, S[21] = { 0 };
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        char func[7];
        scanf("%s", func);
        scanf("%d", &num);

        if (func[0] == 'a' && func[1] == 'd') {
            S[num] = 1;
        }
        else if (func[0] == 'r') {
            S[num] = 0;
        }
        else if (func[0] == 'c') {
            if (S[num] == 1) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
        else if (func[0] == 't') {
            if (S[num] == 1) {
                S[num] = 0;
            }
            else {
                S[num] = 1;
            }
        }
        else if (func[0] == 'a' && func[1] == 'l') {
            for (int j = 1; j < 21; j++) {
                S[j] = 1;
            }
        }
        else { //empty
            for (int j = 1; j < 21; j++) {
                S[j] = 0;
            }
        }
    }

    return 0;
}