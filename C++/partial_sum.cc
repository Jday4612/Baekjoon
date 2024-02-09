#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, S, cnt = 1000000000, sum = 0, start = 0, end = 0;
    cin >> N >> S;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    while (start <= end) {
        if (S <= sum) {
            cnt = min(cnt, end - start);
            sum -= v[start++];
        }
        else if (end == N)
            break;
        else
            sum += v[end++];
    }

    if (cnt == 1000000000)
        cout << "0";
    else
        cout << cnt;

    return 0;
}