#include <iostream>
#include <algorithm>
using namespace std;

void solve();
int N, arr[100000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    solve();

    return 0;
}

void solve() {
    int left = 0, right = N - 1, ans = 2000000000, i, j, tmp;

    while (left < right) {
        tmp = arr[left] + arr[right];

        if (abs(tmp) < abs(ans)) {
            ans = tmp;
            i = arr[left];
            j = arr[right];
        }
        
        if (tmp == 0)
            break;
        else if (0 < tmp)
            right--;
        else
            left++;
    }

    cout << i << " " << j;
}