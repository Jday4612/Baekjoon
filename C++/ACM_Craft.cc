#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T, N, K, X, Y, W;

    cin >> T;

    for (int i = 0; i < T; i++) {
        vector<int> D(1001, 0);
        vector<int> next[1001];
        vector<int> order(1001, 0);
        vector<int> sum(1001, 0);
        queue<int> q;

        cin >> N >> K;

        for (int j = 1; j <= N; j++) {
            cin >> D[j];
            sum[j] = D[j];
        }

        for (int j = 0; j < K; j++) {
            cin >> X >> Y;
            next[X].push_back(Y);
            order[Y]++;
        }

        cin >> W;

        for (int k = 1; k <= N; k++) {
            if (!order[k])
                q.push(k);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int z = 0; z < next[cur].size(); z++) {
                int tmp = next[cur][z];

                if (sum[tmp] < sum[cur] + D[tmp])
                    sum[tmp] = sum[cur] + D[tmp];

                order[tmp]--;

                if (!order[tmp])
                    q.push(tmp);
            }
        }

        cout << sum[W] << "\n";
    }

    return 0;
}