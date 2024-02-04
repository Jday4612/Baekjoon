#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dijkstra();
int N, M, S, E, C, dist[1001], route[1001];
vector<pair<int, int>> bus[1001];
vector<int> r;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> S >> E >> C;
        bus[S].push_back({ E, C });
    }

    for (int j = 1; j <= N; j++)
        dist[j] = 100000000;

    cin >> S >> E;

    dijkstra();

    return 0;
}

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, S });
    dist[S] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first, cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost)
            continue;

        for (int i = 0; i < bus[cur].size(); i++) {
            int ncost = bus[cur][i].second, next = bus[cur][i].first;

            if (cost + ncost < dist[next]) {
                dist[next] = cost + ncost;
                route[next] = cur;
                pq.push({ dist[next], next });
            }
        }
    }

    cout << dist[E] << "\n";

    int tmp = E;
    while (tmp) {
        r.push_back(tmp);
        tmp = route[tmp];
    }

    cout << r.size() << "\n";

    for (int i = r.size() - 1; 0 <= i; i--)
        cout << r[i] << " ";
}