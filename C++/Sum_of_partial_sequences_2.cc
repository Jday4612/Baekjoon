#include <iostream>
#include <map>
using namespace std;

void leftSum(int idx, int sum);
void rightSum(int idx, int sum);
int N, S, arr[40];
long long ans = 0;
map<int, int> seq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> S;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    leftSum(0, 0);
    rightSum(N / 2, 0);

    if (S == 0)
        cout << ans - 1;
    else
        cout << ans;

    return 0;
}

void leftSum(int idx, int sum) {
    if (idx == N / 2) {
        seq[sum]++;
        return;
    }

    leftSum(idx + 1, sum);
    leftSum(idx + 1, sum + arr[idx]);
}

void rightSum(int idx, int sum) {
    if (idx == N) {
        ans += seq[S - sum];
        return;
    }

    rightSum(idx + 1, sum);
    rightSum(idx + 1, sum + arr[idx]);
}