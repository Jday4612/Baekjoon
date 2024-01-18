#include <iostream>
#include <algorithm>
using namespace std;

int N, M, arr[8], N_list[8], visited[8] = { 0 };
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
        int check = 0;

        for (int i = 0; i < N; i++) {
            if (visited[i] == 0 && N_list[i] != check) {
                arr[cnt] = check = N_list[i];
                visited[i] = 1;
                dfs(cnt + 1);
                visited[i] = 0;
            }
        }
    }
}