#include <iostream>
#include <queue>
#include <set>
using namespace std;

void solve();
void bfs(int x, int y);
int N, M, num = 0, map[1000][1000], visited[1000][1000] = { 0 };
int group[1000][1000], area[1000000], ans[1000][1000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> s;

        for (int j = 0; j < M; j++)
            map[i][j] = s[j] - '0';
    }

    solve();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << ans[i][j] % 10;
        cout << "\n";
    }

    return 0;
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && !visited[i][j]) {
                num++;
                bfs(i, j);
            }
        }
    }

    int sum;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                sum = 1;
                set<int> s;

                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k], ny = j + dy[k];

                    if (nx < 0 || N <= nx || ny < 0 || M <= ny || map[nx][ny] == 1)
                        continue;

                    if (s.find(group[nx][ny]) == s.end()) {
                        sum += area[group[nx][ny]];
                        s.insert(group[nx][ny]);
                    }
                }

                ans[i][j] = sum;
            }
        }
    }
}

void bfs(int x, int y) {
    int cnt = 1;
    queue<pair<int, int>> q;
    
    q.push({ x, y });
    visited[x][y] = 1;

    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        group[cx][cy] = num;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];

            if (nx < 0 || N <= nx || ny < 0 || M <= ny || visited[nx][ny] == 1 || map[nx][ny] == 1)
                continue;

            q.push({ nx, ny });
            visited[nx][ny] = 1;
            cnt++;
        }
    }

    area[num] = cnt;
}