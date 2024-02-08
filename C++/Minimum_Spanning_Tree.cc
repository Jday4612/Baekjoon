#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Find(int x);
void Union(int x, int y);
bool SameParent(int x, int y);
int parent[10001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int V, E, A, B, C, ans = 0;
    vector<pair<int, pair<int, int>>> v;

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        v.push_back({ C, { A, B } });
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= V; i++)
        parent[i] = i;

    for (int j = 0; j < E; j++) {
        if (!SameParent(v[j].second.first, v[j].second.second)) {
            Union(v[j].second.first, v[j].second.second);
            ans += v[j].first;
        }
    }

    cout << ans;

    return 0;
}

int Find(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    parent[y] = x;
}

bool SameParent(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y)
        return true;
    else
        return false;
}