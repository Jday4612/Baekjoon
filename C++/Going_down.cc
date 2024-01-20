#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, input[3], minDP[3] = { 0 }, maxDP[3] = { 0 }, tmp1, tmp2;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> input[0] >> input[1] >> input[2];

        tmp1 = minDP[0], tmp2 = minDP[2];
        minDP[0] = min(minDP[0], minDP[1]) + input[0];
        minDP[2] = min(minDP[1], minDP[2]) + input[2];
        minDP[1] = min(tmp1, min(minDP[1],tmp2)) + input[1];

        tmp1 = maxDP[0], tmp2 = maxDP[2];
        maxDP[0] = max(maxDP[0], maxDP[1]) + input[0];
        maxDP[2] = max(maxDP[1], maxDP[2]) + input[2];
        maxDP[1] = max(tmp1, max(maxDP[1], tmp2)) + input[1];
    }

    cout << max(maxDP[0], max(maxDP[1], maxDP[2])) << " " << min(minDP[0], min(minDP[1], minDP[2]));

    return 0;
}