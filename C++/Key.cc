#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

void bfs(int x, int y);
int h, w, ans;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
bool key[26], visited[102][102];
char map[102][102];
string first_key;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    string str;

    cin >> T;

    for (int i = 0; i < T; i++) {
        ans = 0;
        memset(key, false, sizeof(key));
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));

        cin >> h >> w;

        for (int j = 1; j <= h; j++)
            for (int k = 1; k <= w; k++)
                cin >> map[j][k];

        cin >> first_key;

        for (int j = 0; j < first_key.length(); j++) {
            if (first_key[j] == '0')
                continue;

            key[first_key[j] - 'a'] = true;
        }

        bfs(0, 0);
        cout << ans << "\n";
    }

    return 0;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    queue<pair<int, int>> door[26];

    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];

            if (0 <= nx && nx <= h + 1 && 0 <= ny && ny <= w + 1) {
                if (visited[nx][ny] || map[nx][ny] == '*')
                    continue;

                visited[nx][ny] = 1;

                if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z') { // 문
                    if (key[map[nx][ny] - 'A']) // 해당 문을 열 수 있는 열쇠 보유 중
                        q.push({ nx ,ny });
                    else // 열쇠 없음
                        door[map[nx][ny] - 'A'].push({ nx ,ny });
                }
                else if ('a' <= map[nx][ny] && map[nx][ny] <= 'z') { // 열쇠
                    q.push({ nx, ny });

                    if (!key[map[nx][ny] - 'a']) { // 가지고 있지 않던 열쇠
                        key[map[nx][ny] - 'a'] = true;

                        while (!door[map[nx][ny] - 'a'].empty()) { // 열쇠가 없어서 열지 못 했던 문들 위치 추가 (이미 지나왔던 경로로 다시 이동 가능)
                            q.push(door[map[nx][ny] - 'a'].front());
                            door[map[nx][ny] - 'a'].pop();
                        }
                    }
                }
                else { // 빈 공간 or 문서
                    q.push({ nx, ny });

                    if (map[nx][ny] == '$')
                        ans++;
                }
            }
        }
    }
}