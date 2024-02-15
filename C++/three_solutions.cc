#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long arr[5000], sol[3] = { 0 };

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, left, right;
    long long ans = 3000000001, tmp;

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    for (int j = 0; j < N - 2; j++) {
        left = j + 1, right = N - 1;

        while (left < right) {
            tmp = arr[j] + arr[left] + arr[right];

            if (abs(tmp) < ans) {
                ans = abs(tmp);
                sol[0] = arr[j];
                sol[1] = arr[left];
                sol[2] = arr[right];
            }

            if (tmp < 0)
                left++;
            else
                right--;
        }
    }
    
    for (int k = 0; k < 3; k++)
        cout << sol[k] << " ";

    return 0;
}