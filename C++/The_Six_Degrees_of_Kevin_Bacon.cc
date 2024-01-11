#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int N, M, kb[101][101] = { 0 };
vector<int> f[101];

void bfs(int a);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, sum, MIN = INT_MAX, idx;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        f[a].push_back(b);
        f[b].push_back(a);
    }

    for (int j = 1; j <= N; j++)
        bfs(j);

    for (int i = 1; i <= N; i++) {
        sum = 0;

        for (int j = 1; j <= N; j++)
            sum += kb[i][j];

        if (sum < MIN) {
            MIN = sum;
            idx = i;
        }
    }

    cout << idx;

    return 0;
}

void bfs(int a) {
    int visited[101] = { 0 };
    queue<int> q;

    q.push(a);
    visited[a] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < f[x].size(); i++) {
            int idx = f[x][i]; // idx : x와 친구 관계 => idx <-> x = 1단계

            if (visited[idx] == 0) { // a의 kb를 구하는 게 최종 목적
                kb[idx][a] = kb[x][a] + 1; // idx -> x -> a = 1 + x - > a
                kb[a][idx] = kb[a][x] + 1; // a -> x -> idx = a - > x + 1

                visited[idx] = 1;
                q.push(idx);
            }
        }
    }
}