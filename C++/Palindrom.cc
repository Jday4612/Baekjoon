#include <iostream>
using namespace std;

int arr[2001], palindrome[2001][2001] = { 0 };

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, S, E;
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        palindrome[i][i] = 1;

        if (i != 1 && arr[i - 1] == arr[i])
            palindrome[i - 1][i] = 1;
    }

    for (int i = 2; i < N; i++) {
        for (int j = 1; i + j <= N; j++) {
            if (arr[j] == arr[j + i] && palindrome[j + 1][j + i - 1] == 1)
                palindrome[j][j + i] = 1;
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> S >> E;
        cout << palindrome[S][E] << "\n";
    }

    return 0;
}