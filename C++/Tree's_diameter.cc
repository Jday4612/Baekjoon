#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void dfs(int x, int dist);
int V, node = 0, ans = 0, visited[100001] = { 0 };
vector<pair<int, int>> line[100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int dot, a, b;

    cin >> V;

    for (int i = 0; i < V; i++) {
        cin >> dot;

        while (true) {
            cin >> a;

            if (a == -1)
                break;

            cin >> b;
            line[dot].push_back({ a, b });
            line[a].push_back({ dot, b });
        }
    }

    dfs(1, 0);

    memset(visited, 0, sizeof(visited));
    ans = 0;
    dfs(node, 0);

    cout << ans;

    return 0;
}

void dfs(int x, int dist) {
    if (ans < dist) {
        node = x;
        ans = dist;
    }

    visited[x] = 1;

    for (int i = 0; i < line[x].size(); i++) {
        int next = line[x][i].first, ndist = dist + line[x][i].second;
        
        if (!visited[next])
            dfs(next, ndist);
    }
}