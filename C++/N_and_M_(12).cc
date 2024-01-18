#include <iostream>
#include <algorithm>
using namespace std;

int N, M, arr[8], N_list[8];
void dfs(int x, int cnt);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> N_list[i];
    sort(N_list, N_list + N);

    dfs(0, 0);

    return 0;
}

void dfs(int x, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    else {
        int check = 0;

        for (int i = x; i < N; i++) {
            if (N_list[i] != check) {
                arr[cnt] = check = N_list[i];
                dfs(i, cnt + 1);
            }
        }
    }
}