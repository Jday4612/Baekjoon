#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve();
int N, order[1001] = { 0 };
vector<int> v[1001];
vector<int> ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int M, cnt, a, b;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> cnt >> a;

        for (int j = 0; j < cnt - 1; j++) {
            cin >> b;
            v[a].push_back(b);
            order[b]++;
            a = b;
        }
    }

    solve();

    if (ans.size() == N) {
        for (int k = 0; k < ans.size(); k++)
            cout << ans[k] << "\n";
    }
    else
        cout << 0;

    return 0;
}

void solve() {
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (!order[i])
            q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            order[next]--;

            if (!order[next])
                q.push(next);
        }
    }
}