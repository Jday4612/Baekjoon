#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, ans = 0, len;
    string S;

    cin >> N >> M >> S;

    for (int i = 0; i < M; i++) {
        len = 0;

        if (S[i] == 'I') {
            while (S[i + 1] == 'O' && S[i + 2] == 'I') {
                len++;

                if (len == N) {
                    ans++;
                    len--;
                }

                i += 2;
            }
        }
    }

    cout << ans;

    return 0;
}