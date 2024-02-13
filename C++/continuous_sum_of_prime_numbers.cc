#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, k, l, sum, ans = 0;

    cin >> N;

    vector<int> v(N + 1, 1);
    vector<int> prime;

    for (int i = 2; i * i <= N; i++) {
        if (v[i] == 0)
            continue;

        for (int j = i + i; j <= N; j += i)
            v[j] = 0;
    }

    for (int i = 2; i <= N; i++) {
        if (v[i])
            prime.push_back(i);
    }

    sum = 0, k = 0, l = 0;

    while (true) {
        if (N < sum) {
            sum -= prime[l];
            l++;
        }
        else {
            if (sum == N)
                ans++;

            if (prime.size() <= k)
                break;

            sum += prime[k];
            k++;
        }
    }

    cout << ans;

    return 0;
}