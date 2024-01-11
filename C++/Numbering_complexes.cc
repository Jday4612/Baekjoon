#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, home[25][25], visited[25][25] = { 0 }, check = 2;
vector<int> v;

void bfs();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;

        for (int j = 0; j < N; j++)
            home[i][j] = s[j] - '0';
    }

    bfs();

    cout << check << "\n";

    sort(v.begin(), v.end());
    for (auto i : v) {
        cout << i << "\n";
    }

    return 0;
}

void bfs() {
    int directX[4] = { 0, 0, 1, -1 }, directY[4] = { -1, 1, 0, 0 }, cnt;
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (home[i][j] == 1) {
                visited[i][j] = 1;
                home[i][j] = check;
                cnt = 1;
                q.push({ i, j });

                while (!q.empty()) {
                    int fx = q.front().first, fy = q.front().second;
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int x = fx + directX[i], y = fy + directY[i];

                        if (0 <= x && x < N && 0 <= y && y < N && visited[x][y] == 0 && home[x][y] == 1) {
                            visited[x][y] = 1;
                            home[x][y] = check;
                            cnt++;
                            q.push({ x, y });
                        }
                    }
                }
                
                check++;
                v.push_back(cnt);
            }
        }
    }

    check -= 2;
}