#include <iostream>
using namespace std;

int Find(int x);
bool Union(int x, int y);
int n, m, parent[500000];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, ans = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int j = 1; j <= m; j++) {
        cin >> a >> b;

        if (Union(a, b)) {
            ans = j;
            break;
        }
    }

    cout << ans;

    return 0;
}

int Find(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y)
        return true;
    else {
        parent[y] = x;
        return false;
    }
}