#include <iostream>
#include <queue>
#include <string>
using namespace std;

void bfs(int A, int B);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T, A, B;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        bfs(A, B);
    }

    return 0;
}

void bfs(int A, int B) {
    int visited[10000] = { 0 }, D, S, L, R;
    queue<pair<int, string>> q;

    q.push({ A, "" });
    visited[A] = 1;

    while (!q.empty()) {
        int n = q.front().first;
        string str = q.front().second;

        q.pop();

        if (n == B) {
            cout << str << "\n";
            break;
        }

        D = n * 2 % 10000;
        if (visited[D] == 0) {
            visited[D] = 1;
            q.push({ D, str + "D" });
        }

        S = n < 1 ? 9999 : n - 1;
        if (visited[S] == 0) {
            visited[S] = 1;
            q.push({ S, str + "S" });
        }

        L = (n % 1000) * 10 + (n / 1000);
        if (visited[L] == 0) {
            visited[L] = 1;
            q.push({ L, str + "L" });
        }

        R = (n % 10) * 1000 + (n / 10);
        if (visited[R] == 0) {
            visited[R] = 1;
            q.push({ R, str + "R" });
        }
    }
}