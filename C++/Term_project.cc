#include <iostream>
#include <cstring>
using namespace std;

void dfs(int cur);
int n, cnt, student[100001], team[100001], visited[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> n;

        for (int j = 1; j <= n; j++)
            cin >> student[j];

        memset(team, 0, sizeof(team));
        memset(visited, 0, sizeof(visited));
        cnt = 0;

        for (int j = 1; j <= n; j++) {
            if (!visited[j])
                dfs(j);
        }

        cout << n - cnt << "\n";
    }

    return 0;
}

void dfs(int cur) {
    visited[cur] = 1;

    int next = student[cur];

    if (!visited[next])
        dfs(next);
    else if (!team[next]) {
        for (int i = next; i != cur; i = student[i])
            cnt++;
        cnt++;
    }

    team[cur] = 1;
}