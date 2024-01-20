#include <iostream>
using namespace std;

void postOrder(int start, int end);
int tree[10000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int node, idx = 0;

    while (cin >> node) {
        tree[idx++] = node;
    }

    postOrder(0, idx);

    return 0;
}

void postOrder(int start, int end) {
    if (start >= end)
        return;

    if (start == end) {
        cout << tree[start] << "\n";
        return;
    }

    int i = start + 1;
    while (i < end) {
        if (tree[start] < tree[i])
            break;
        i++;
    }

    postOrder(start + 1, i);
    postOrder(i, end);
    cout << tree[start] << "\n";
}