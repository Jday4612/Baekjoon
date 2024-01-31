#include <iostream>
#include <queue>
using namespace std;

#define INF 16
void dijkstra(int x);
int n, m, r, t[101], a, b, l, d[101], ans = 0;
vector<pair<int, int>> road[101];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
        cin >> t[i];

    for (int i = 0; i < r; i++) {
        cin >> a >> b >> l;
        road[a].push_back({ b, l });
        road[b].push_back({ a, l });
    }

    for (int i = 1; i <= n; i++)
        dijkstra(i);

    cout << ans;

    return 0;
}

void dijkstra(int x) {
    int cnt = 0;
    queue<int> q;

    for (int i = 1; i <= n; i++)
        d[i] = INF;

    d[x] = 0;
    q.push(x);

    while (!q.empty()) {
        int cur = q.front(), dist = d[cur];
        q.pop();

        for (int i = 0; i < road[cur].size(); i++) {
            int next = road[cur][i].first, ndist = road[cur][i].second;

            if (dist + ndist < d[next]) {
                d[next] = dist + ndist;
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] <= m)
            cnt += t[i];
    }

    ans = ans < cnt ? cnt : ans;
}