#include <iostream>
#include <vector>
using namespace std;

int TC, N, M, W, dist[501];
vector<pair<pair<int, int>, int>> road;

void bellmanford();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int S, E, T;

    cin >> TC;
    
    for (int i = 0; i < TC; i++) {
        cin >> N >> M >> W;
        road.clear();

        for (int j = 1; j <= N; j++)
            dist[j] = 5000000;

        for (int k = 0; k < M; k++) {
            cin >> S >> E >> T;
            road.push_back({ { S, E }, T });
            road.push_back({ { E, S }, T });
        }

        for (int l = 0; l < W; l++) {
            cin >> S >> E >> T;
            road.push_back({ { S, E }, -T });
        }

        bellmanford();
    }

    return 0;
}

void bellmanford() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < road.size(); j++) {
            int start = road[j].first.first, end = road[j].first.second, time = road[j].second;

            if (dist[start] + time < dist[end])
                dist[end] = dist[start] + time;
        }
    }

    for (int i = 0; i < road.size(); i++) {
        int start = road[i].first.first, end = road[i].first.second, time = road[i].second;

        if (dist[start] + time < dist[end]) { // 경로가 없고 웜홀만 있으면
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}