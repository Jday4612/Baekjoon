#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void bfs();
int N, K, visited[100001] = { 0 };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    bfs();

    return 0;
}

void bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    visited[N] = 1;
    q.push({ 0, N });

    while (!q.empty()) {
        int T = q.top().first;
        int X = q.top().second;

        q.pop();

        if (X == K) {
            cout << T;
            break;
        }

        if (X * 2 <= 100000 && visited[X * 2] == 0) {
            visited[X * 2] = 1;
            q.push({ T, X * 2 });
        }

        if (0 <= X - 1 && visited[X - 1] == 0) {
            visited[X - 1] = 1;
            q.push({ T + 1, X - 1 });
        }

        if (X + 1 <= 100000 && visited[X + 1] == 0) {
            visited[X + 1] = 1;
            q.push({ T + 1, X + 1 });
        }
    }
}