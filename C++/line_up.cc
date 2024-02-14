#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve();
int N, M, order[32001] = { 0 };
vector<int> S[32001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int A, B;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        order[B]++;
        S[A].push_back(B);
    }

    solve();

    return 0;
}

void solve() {
    int cur, next;
    queue<int> q;

    for (int j = 1; j <= N; j++) {
        if (!order[j])
            q.push(j);
    }

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int i = 0; i < S[cur].size(); i++) {
            next = S[cur][i];
            order[next]--;

            if (!order[next])
                q.push(next);
        }
    }
}