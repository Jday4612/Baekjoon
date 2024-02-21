#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void solve();
int N, K, C[300000];
vector<pair<int, int>> MV;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int M, V;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> M >> V;
        MV.push_back({ M, V });
    }

    for (int i = 0; i < K; i++)
        cin >> C[i];

    solve();

    return 0;
}

void solve() {
    sort(MV.begin(), MV.end());
    sort(C, C + K);

    priority_queue<int, vector<int>, less<int>> pq;
    int idx = 0;
    long long ans = 0;

    for (int i = 0; i < K; i++) {
        while (idx < N && MV[idx].first <= C[i]) {
            pq.push(MV[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
}