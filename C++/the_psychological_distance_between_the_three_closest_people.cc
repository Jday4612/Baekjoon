#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T, N, distance;
    string mbti[100000];

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;

        for (int j = 0; j < N; j++)
            cin >> mbti[j];

        if (32 < N) {
            cout << 0 << '\n';
        }
        else {
            distance = 8;

            for (int k = 0; k < N - 2; k++) {
                for (int m = k + 1; m < N - 1; m++) {
                    for (int p = m + 1; p < N; p++) {
                        int tmp = 0;

                        for (int q = 0; q < 4; q++) {
                            if (mbti[k][q] != mbti[m][q])
                                tmp++;

                            if (mbti[m][q] != mbti[p][q])
                                tmp++;

                            if (mbti[p][q] != mbti[k][q])
                                tmp++;
                        }
                        distance = (tmp < distance) ? tmp : distance;
                    }
                }
            }

            cout << distance << "\n";
        }
    }

    return 0;
}