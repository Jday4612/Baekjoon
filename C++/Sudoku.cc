#include <iostream>
#include <vector>
using namespace std;

void DFS(int n);
bool check(int x, int y, int num);
int puzzle[9][9], visited[81] = { 0 }, cnt = 0;
vector<pair<int, int>> empty_space;
bool flag = false;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s;

    for (int i = 0; i < 9; i++) {
        cin >> s;
        
        for (int j = 0; j < 9; j++) {
            puzzle[i][j] = s[j] - '0';

            if (puzzle[i][j] == 0) {
                empty_space.push_back({ i, j });
                cnt++;
            }
        }
    }

    DFS(0);

    return 0;
}

void DFS(int n) {
    if (n == cnt) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << puzzle[i][j];

            cout << "\n";
        }

        flag = true;
        return;
    }

    if (visited[n])
        return;

    visited[n] = 1;

    int x = empty_space[n].first, y = empty_space[n].second;

    for (int i = 1; i <= 9; i++) {
        if (check(x, y, i)) {
            puzzle[x][y] = i;
            DFS(n + 1);

            /*if (flag)
                return;*/

            puzzle[x][y] = 0;
        }
    }

    if (flag)
        return;

    visited[n] = 0;
}

bool check(int x, int y, int num) {
    for (int i = 0; i < 9; i++) {
        if (puzzle[x][i] == num || puzzle[i][y] == num)
            return false;
    }

    x = x / 3 * 3;
    y = y / 3 * 3;

    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            if (puzzle[x + j][y + k] == num)
                return false;
        }
    }

    return true;
}