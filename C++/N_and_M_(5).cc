#include <iostream>
#include <algorithm>
using namespace std;

int N, M, arr[9], N_list[8], visited[9] = { 0 };
void dfs(int cnt);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> N_list[i];
    sort(N_list, N_list + N);

    dfs(0);

    return 0;
}

void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    else {
        for (int i = 1; i <= N; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                arr[cnt] = N_list[i - 1];
                dfs(cnt + 1);
                visited[i] = 0;
            }
        }
    }
}