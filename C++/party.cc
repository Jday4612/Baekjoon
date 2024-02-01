#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 100000
int N, M, X;
vector<pair<int, int>> v[2][1001];
vector<int> dist[2];

void dijstra(int p);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int start, end, T, ans = 0;

    cin >> N >> M >> X;
    
    for (int i = 0; i < M; i++) {
        cin >> start >> end >> T;
        v[0][start].push_back({ end, T });
        v[1][end].push_back({ start, T });
    }

    dijstra(0);
    dijstra(1);

    for (int i = 1; i <= N; i++)
        ans = max(ans, dist[0][i] + dist[1][i]);

    cout << ans;

    return 0;
}

void dijstra(int p) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[p].resize(N + 1, INF);

    dist[p][X] = 0;
    pq.push({ 0, X });

    while (!pq.empty()) {
        int time = pq.top().first, cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[p][cur].size(); i++) {
            int ntime = v[p][cur][i].second, next = v[p][cur][i].first;

            if (ntime + time < dist[p][next]) {
                dist[p][next] = ntime + time;
                pq.push({ dist[p][next], next });
            }
        }
    }
}