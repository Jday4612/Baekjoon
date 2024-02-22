#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void solve();
int N, M, order[32001] = { 0 };
vector<int> problem[32001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int A, B;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        problem[A].push_back(B);
        order[B]++;
    }

    solve();

    return 0;
}

void solve() {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; i++) {
        if (order[i] == 0)
            pq.push(i);
    }

    while (!pq.empty()) {
        int cur = pq.top();

        cout << cur << " ";
        pq.pop();

        for (int i = 0; i < problem[cur].size(); i++) {
            int next = problem[cur][i];

            order[next]--;

            if (order[next] == 0)
                pq.push(next);
        }
    }
}