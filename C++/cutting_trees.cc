#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, x, low, mid, high, result = 0;
    vector<int> H;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> x;
        H.push_back(x);
    }
    
    low = 0;
    high = *max_element(H.begin(), H.end());

    while (low <= high) {
        long long tmp = 0;
        mid = (low + high) / 2;

        for (int i = 0; i < N; i++) {
            if (H[i] > mid)
                tmp += H[i] - mid;
        }

        if (tmp < M)
            high = mid - 1;
        else {
            result = mid;
            low = mid + 1;
        }
    }

    cout << result;

    return 0;
}