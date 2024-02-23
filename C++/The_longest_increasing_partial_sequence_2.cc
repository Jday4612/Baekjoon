#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int A, x, idx;
    vector<int> arr;

    cin >> A;

    for (int i = 0; i < A; i++) {
        cin >> x;
        
        if (arr.empty() || arr.back() < x) // 비어 있을 때 추가 or 가장 마지막보다 x가 크면 추가(증가 수열)
            arr.push_back(x);
        else {
            idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            arr[idx] = x;
        }
    }

    cout << arr.size();

    return 0;
}