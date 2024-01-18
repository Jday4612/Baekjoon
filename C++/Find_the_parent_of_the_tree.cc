#include <iostream>
#include <vector>
using namespace std;

int parent[100001] = { 0 };
vector<int> tree[100001];

void dfs(int x);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, a, b;

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}

void dfs(int x) {
    for (int i = 0; i < tree[x].size(); i++) {
        int next = tree[x][i];

        if (parent[next] == 0) {
            parent[next] = x;
            dfs(next);
        }
    }
}