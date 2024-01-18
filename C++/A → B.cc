#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int A, B, ans = -1;
    queue<pair<long int, int>> q;

    cin >> A >> B;

    q.push({ A, 1 });

    while (!q.empty()) {
        long int num = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (num == B) {
            ans = cnt;
            break;
        }

        if (num * 2 <= B)
            q.push({ num * 2, cnt + 1 });
        
        if (num * 10 + 1 <= B)
            q.push({ num * 10 + 1, cnt + 1 });
    }

    cout << ans;

    return 0;
}