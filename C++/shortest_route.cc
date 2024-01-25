#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 3000000
void solve();
int V, E, K, u, v, w, dist[20001];
vector<pair<int, int>> edge[20001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> V >> E >> K;

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({ v, w });
    }

    for (int i = 1; i <= V; i++)
        dist[i] = INF;

    solve();

    return 0;
}

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, K });
    dist[K] = 0;

    while (!pq.empty()) {
        int weight = pq.top().first, cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < edge[cur].size(); i++) {
            int next = edge[cur][i].first, newweight = weight + edge[cur][i].second;

            if (newweight < dist[next]) {
                dist[next] = newweight;
                pq.push({ newweight, next });
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}