#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool check(pair<int, int> A, pair<int, int> B, pair<int, int> C, pair<int, int> D);
int CCW(pair<int, int> A, pair<int, int> B, pair<int, int> C);
int CCW(pair<int, int> A, pair<int, int> B, pair<int, int> C);
int Find(int x);
bool Union(int x, int y);
void BFS(int x);

int N, parent[3001], visit[3001] = { 0 }, ans_seg = 0;
vector<pair<int, int>> v[3001];
vector<int> connect[3001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int x1, x2, y1, y2, ans_group = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        v[i].push_back({ x1, y1 });
        v[i].push_back({ x2, y2 });
        parent[i] = i;
    }

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (check(v[i][0], v[i][1], v[j][0], v[j][1]))
                Union(i, j);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!visit[i]) {
            ans_group++;
            BFS(i);
        }
    }

    cout << ans_group << "\n" << ans_seg;

    return 0;
}

bool check(pair<int, int> A, pair<int, int> B, pair<int, int> C, pair<int, int> D) {
    int tmp1 = CCW(A, B, C) * CCW(A, B, D);
    int tmp2 = CCW(C, D, A) * CCW(C, D, B);

    if (tmp1 == 0 && tmp2 == 0) {
        if (B < A)
            swap(A, B);

        if (D < C)
            swap(C, D);

        return (A <= D && C <= B);
    }
    else
        return (tmp1 <= 0 && tmp2 <= 0);
}

int CCW(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    int tmp = (A.first * B.second + B.first * C.second + C.first * A.second) - (B.first * A.second + C.first * B.second + A.first * C.second);

    if (0 < tmp)
        return 1;
    else if (tmp < 0)
        return -1;

    return 0;
}

int Find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y)
        return false;
    else {
        parent[y] = x;

        connect[x].push_back(y);
        connect[y].push_back(x);

        return true;
    }
}

void BFS(int x) {
    int ans = 1;
    queue<int> q;

    q.push(x);

    while (!q.empty()) {
        int cx = q.front();
        q.pop();

        visit[cx] = 1;

        for (int i = 0; i < connect[cx].size(); i++) {
            int nx = connect[cx][i];

            if (!visit[nx]) {
                ans++;
                q.push(nx);
            }
        }
    }

    ans_seg = max(ans_seg, ans);
}