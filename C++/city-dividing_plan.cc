#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Find(int x);
void Union(int x, int y);
bool SameParent(int x, int y);
int parent[100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, A, B, C, ans = 0, maxCost = 0;
    vector<pair<int, pair<int, int>>> v;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        v.push_back({ C, { A, B } });
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int j = 0; j < M; j++) {
        int cost = v[j].first;

        if (!SameParent(v[j].second.first, v[j].second.second)) {
            maxCost = max(maxCost, cost);
            Union(v[j].second.first, v[j].second.second);
            ans += cost;
        }
    }

    cout << ans - maxCost;

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