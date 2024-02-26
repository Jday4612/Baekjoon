#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int len, DP[2501];
bool Palindrom[2501][2501];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> str;

    str = " " + str;
    len = str.length();

    for (int i = 1; i <= len; i++) // 1개
        Palindrom[i][i] = true;

    for (int i = 1; i < len; i++) { // 2개
        if (str[i] == str[i + 1])
            Palindrom[i][i + 1] = true;
    }

    for (int i = 2; i < len; i++) { // 3개 이상
        for (int j = 1; j <= len - i; j++) {
            if (str[j] == str[j + i] && Palindrom[j + 1][j + i - 1])
                Palindrom[j][j + i] = true;
        }
    }

    for (int i = 1; i <= len; i++) {
        DP[i] = 2501;

        for (int j = 1; j <= i; j++) {
            if (Palindrom[j][i])
                DP[i] = min(DP[i], DP[j - 1] + 1);
        }
    }

    cout << DP[len - 1];

    return 0;
}