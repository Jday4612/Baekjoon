#include <iostream>
#include <cstdlib>
using namespace std;

void nqueen(int x);
int N, ans = 0, col[15];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    nqueen(0);
    cout << ans;

    return 0;
}

void nqueen(int x) {
    if (x == N)
        ans++;
    else {
        for (int i = 0; i < N; i++) {
            col[x] = i;
            bool check = true;

            for (int j = 0; j < x; j++) {
                if (col[x] == col[j] || abs(col[x] - col[j]) == x - j) {
                    check = false;
                    break;
                }
            }

            if (check)
                nqueen(x + 1);
        }
    }
}