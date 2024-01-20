#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, A, B, C, start, end, cost[1001];
    vector<pair<int, int>> v[1001];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cost[i] = 100000000;

    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        v[A].push_back({ B, C });
    }

    cin >> start >> end;

    q.push({ 0, start });
    cost[start] = 0;

    while (!q.empty()) {
        int sum = q.top().first, cur = q.top().second;
        q.pop();

        if (cost[cur] < sum)
            continue;

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first, tmp = v[cur][i].second + sum;

            if (cost[next] > tmp) {
                cost[next] = tmp;
                q.push({ tmp, next });
            }
        }
    }
    
    cout << cost[end];

    return 0;
}