#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 200000000
void dijkstra(int start);
int N, E, a, b, c, v1, v2, dist[801];
vector<pair<int, int>> V[801];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        V[a].push_back({ b, c });
        V[b].push_back({ a, c });
    }

    cin >> v1 >> v2;

    long long int ans, one_to_v1, one_to_v2, v1_to_v2, v1_to_N, v2_to_N, v2_to_v1;

    dijkstra(1);
    one_to_v1 = dist[v1], one_to_v2 = dist[v2];

    dijkstra(v1);
    v1_to_v2 = dist[v2], v1_to_N = dist[N];

    dijkstra(v2);
    v2_to_N = dist[N], v2_to_v1 = dist[v1];
    
    ans = min(one_to_v1 + v1_to_v2 + v2_to_N, one_to_v2 + v2_to_v1 + v1_to_N);

    if (ans >= INF)
        ans = -1;
    
    cout << ans;

    return 0;
}

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= N; i++)
        dist[i] = INF;

    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first, cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost)
            continue;

        for (int i = 0; i < V[cur].size(); i++) {
            int next = V[cur][i].first, newcost = cost + V[cur][i].second;

            if (newcost < dist[next]) {
                dist[next] = newcost;
                pq.push({ newcost, next });
            }
        }
    }
}