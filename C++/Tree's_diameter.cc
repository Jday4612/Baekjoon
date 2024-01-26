#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, int len);
int n, a, b, c, ans = 0, endpoint = 0, visited[10001] = { 0 };
vector<pair<int, int>> node[10001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        node[a].push_back({ b, c });
        node[b].push_back({ a, c });
    }

    dfs(1, 0);

    ans = 0;
    fill(visited, visited + n + 1, 0);
    dfs(endpoint, 0);

    cout << ans;

    return 0;
}

void dfs(int start, int len) {
    if (visited[start])
        return;

    visited[start] = 1;

    if (ans < len) {
        ans = len;
        endpoint = start;
    }

    for (int i = 0; i < node[start].size(); i++)
        dfs(node[start][i].first, len + node[start][i].second);
}