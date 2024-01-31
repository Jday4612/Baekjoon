#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, safe = 0, map[8][8], visited[8][8];
vector<pair<int, int>> blank, virus;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int solve();
void dfs(int x, int y);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 0)
                blank.push_back({ i, j });
            if (map[i][j] == 2)
                virus.push_back({ i,j });
        }
    }

    for (int i = 0; i < blank.size(); i++) { // 벽 3개 추가 생성
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                map[blank[i].first][blank[i].second] = 1;
                map[blank[j].first][blank[j].second] = 1;
                map[blank[k].first][blank[k].second] = 1;
                safe = max(safe, solve());
                map[blank[i].first][blank[i].second] = 0;
                map[blank[j].first][blank[j].second] = 0;
                map[blank[k].first][blank[k].second] = 0;
            }
        }
    }

    cout << safe;

    return 0;
}

int solve() {
    int cnt = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = 0;

    for (int i = 0; i < virus.size(); i++) {
        visited[virus[i].first][virus[i].second] = 1;
        dfs(virus[i].first, virus[i].second);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && visited[i][j] == 0)
                cnt++;
        }
    }

    return cnt;
}

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (0 <= nx && nx < N && 0 <= ny && ny < M && map[nx][ny] != 1 && visited[nx][ny] == 0) {
            visited[nx][ny] = 1;
            dfs(nx, ny);
        }
    }
}