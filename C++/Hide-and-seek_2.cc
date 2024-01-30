#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K, ans, cnt = 0, visited[100001] = { 0 };
    queue<pair<int, int>> q;

    cin >> N >> K;

    q.push({ N, 0 });

    while (!q.empty()) {
        int cur = q.front().first, time = q.front().second, next;

        visited[cur] = 1;
        q.pop();

        if (cur == K) {
            if (!cnt) {
                ans = time;
                cnt++;
            }
            else if (cnt && ans == time)
                cnt++;
        }

        next = cur - 1;
        if (0 <= next && next <= 100000 && visited[next] == 0)
            q.push({ next, time + 1 });

        next = cur + 1;
        if (0 <= next && next <= 100000 && visited[next] == 0)
            q.push({ next, time + 1 });

        next = cur * 2;
        if (0 <= next && next <= 100000 && visited[next] == 0)
            q.push({ next, time + 1 });
    }

    cout << ans << "\n" << cnt;

    return 0;
}