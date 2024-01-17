#include <iostream>
#include <algorithm>
using namespace std;

int N, M, arr[9], N_list[8], visited[9] = { 0 };
void dfs(int x, int cnt);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> N_list[i];
    sort(N_list, N_list + N);

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
            arr[cnt] = N_list[i - 1];
            dfs(i, cnt + 1);
        }
    }
}