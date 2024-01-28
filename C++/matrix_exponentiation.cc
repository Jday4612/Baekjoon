#include <iostream>
using namespace std;

void square(int x[5][5], int y[5][5]);
long long B;
int N, matrix[5][5], ans[5][5];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];
        ans[i][i] = 1;
    }

    while (B) {
        if (B % 2 == 1)
            square(ans, matrix);

        square(matrix, matrix);
        B /= 2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

void square(int x[5][5], int y[5][5]) {
    int tmp[5][5];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = 0;

            for (int k = 0; k < N; k++)
                tmp[i][j] += x[i][k] * y[k][j];

            tmp[i][j] %= 1000;
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            x[i][j] = tmp[i][j];
}