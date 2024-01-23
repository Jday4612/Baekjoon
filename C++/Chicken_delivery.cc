#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

void dfs(int cnt, int idx);

int N, M, num, ans = INT_MAX;
vector<pair<int, int>> house, chicken;
vector<int> selected;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num;

            if (num == 1)
                house.push_back({ i, j });
            else if (num == 2)
                chicken.push_back({ i, j });
        }
    }

    dfs(0, 0);
    cout << ans;

    return 0;
}

void dfs(int cnt, int idx) {
    if (cnt == M) {
        int disSum = 0;

        for (auto& h : house) {
            int dis = INT_MAX;

            for (int i : selected)
                dis = min(dis, abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));

            disSum += dis;
        }

        ans = min(ans, disSum);
        return;
    }

    for (int i = idx; i < chicken.size(); i++) {
        selected.push_back(i);
        dfs(cnt + 1, i + 1);
        selected.pop_back();
    }
}