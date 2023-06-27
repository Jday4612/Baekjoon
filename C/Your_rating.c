#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    float a = 0.0;
    float sum = 0.0;

    for (int i = 0; i < 20; i++) {
        char name[51];
        float grade;
        char rating[3];

        scanf("%s", name);
        scanf("%f", &grade);
        scanf("%s", rating);


        if (rating[0] != 'P') {
            sum += grade;
        }

        if (rating[0] == 'A') {
            if (rating[1] == '+') {
                a += grade * 4.5;
            }
            else if (rating[1] == '0') {
                a += grade * 4.0;
            }
        }
        else if (rating[0] == 'B') {
            if (rating[1] == '+') {
                a += grade * 3.5;
            }
            else if (rating[1] == '0') {
                a += grade * 3.0;
            }
        }
        else if (rating[0] == 'C') {
            if (rating[1] == '+') {
                a += grade * 2.5;
            }
            else if (rating[1] == '0') {
                a += grade * 2.0;
            }
        }
        else if (rating[0] == 'D') {
            if (rating[1] == '+') {
                a += grade * 1.5;
            }
            else if (rating[1] == '0') {
                a += grade * 1.0;
            }
        }
        else {
            a += grade * 0.0;
        }
    }

    printf("%f", a / sum);

    return 0;
}