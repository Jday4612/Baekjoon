#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int Find(int x);
void Union(int x, int y);
double Distance(double x1, double y1, double x2, double y2);
int parent[100];
vector<pair<double, double>> coord;
vector<pair<double, pair<int, int>>> edge;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    double x, y, cost, ans = 0;
    int n, a, b;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coord.push_back({ x, y });
        parent[i] = i;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double tmp = Distance(coord[i].first, coord[i].second, coord[j].first, coord[j].second);
            edge.push_back({ tmp, {i, j} });
        }
    }

    sort(edge.begin(), edge.end());

    for (int i = 0; i < edge.size(); i++) {
        cost = edge[i].first;
        a = edge[i].second.first;
        b = edge[i].second.second;

        if (Find(a) != Find(b)) {
            Union(a, b);
            ans += cost;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}

int Find(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x != y)
        parent[y] = x;
}

double Distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}