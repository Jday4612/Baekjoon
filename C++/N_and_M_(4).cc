#include <iostream>
using namespace std;

int N, M, arr[9];
void dfs(int x, int cnt);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    dfs(1, 0);

    return 0;
}

void dfs(int x, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    else {
        for (int i = x; i <= N; i++) {
            arr[cnt] = i;
            dfs(i, cnt + 1);
        }
    }
}