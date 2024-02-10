#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void LCS(int i, int j);
string A, B;
int DP[1001][1001] = { 0 };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> A >> B;

    for (int i = 1; i <= A.length(); i++) {
        for (int j = 1; j <= B.length(); j++) {
            if (A[i - 1] == B[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }

    cout << DP[A.length()][B.length()] << "\n";

    LCS(A.length(), B.length());

    return 0;
}

void LCS(int i, int j) {
    if (!DP[i][j])
        return;

    if (A[i - 1] == B[j - 1]) {
        LCS(i - 1, j - 1);
        cout << A[i - 1];
    }
    else {
        if (DP[i - 1][j] > DP[i][j - 1])
            LCS(i - 1, j);
        else
            LCS(i, j - 1);
    }
}