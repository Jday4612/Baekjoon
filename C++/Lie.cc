#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, T, person, cnt, ans = 0;
    bool lie[50];
    memset(lie, false, sizeof(lie));
    queue<int> q;
    
    cin >> N >> M >> T;

    vector<bool> truth(N + 1, false);
    vector<vector<int>> party(M);

    for (int i = 0; i < T; i++) {
        cin >> person;
        truth[person] = true;
        q.push(person);
    }

    for (int i = 0; i < M; i++) {
        cin >> cnt;
        party[i].resize(cnt);

        for (int j = 0; j < cnt; j++)
            cin >> party[i][j];
    }

    while (!q.empty()) {
        person = q.front();
        q.pop();

        for (int i = 0; i < M; i++) {
            if (find(party[i].begin(), party[i].end(), person) != party[i].end()) {
                lie[i] = true;

                if (party[i].size() > 1) {
                    for (int p : party[i]) {
                        if (!truth[p]) {
                            truth[p] = true;
                            q.push(p);
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < M; i++) {
        if (!lie[i])
            ans++;
    }

    cout << ans;
    
    return 0;
}