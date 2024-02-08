#include <iostream>
#include <algorithm>
using namespace std;

int N, x[1000001], card[1000001], score[1000001] = { 0 };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> x[i];
        card[x[i]] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = x[i] * 2; j < 1000001; j += x[i]) {
            if (card[j] == 1) {
                score[x[i]]++;
                score[j]--;
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << score[x[i]] << " ";

    return 0;
}