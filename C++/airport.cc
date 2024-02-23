#include <iostream>
using namespace std;

int Find(int x);
void Union(int x, int y);
int G, P, parent[100001] = { 0 };

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int g, ans = 0;

    cin >> G >> P;

    for (int i = 1; i <= G; i++)
        parent[i] = i;

    for (int i = 1; i <= P; i++) {
        cin >> g;

        if (!Find(g))
            break;
        else {
            ans++;
            Union(Find(g), Find(g) - 1);
        }
    }

    cout << ans;

    return 0;
}

int Find(int x) {
    if (parent[x] == x)
        return x;
    
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x != y)
        parent[x] = y;
}