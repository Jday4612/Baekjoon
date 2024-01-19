#include <iostream>
using namespace std;

pair<char, char> tree[26];

void preorder(char x);
void inorder(char x);
void postorder(char x);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    char p, left, right;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> p >> left >> right;
        tree[p - 'A'].first = left;
        tree[p - 'A'].second = right;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');

    return 0;
}

void preorder(char x) {
    if (x != '.') {
        cout << x;
        preorder(tree[x - 'A'].first);
        preorder(tree[x - 'A'].second);
    }
}

void inorder(char x) {
    if (x != '.') {
        inorder(tree[x - 'A'].first);
        cout << x;
        inorder(tree[x - 'A'].second);
    }
}

void postorder(char x) {
    if (x != '.') {
        postorder(tree[x - 'A'].first);
        postorder(tree[x - 'A'].second);
        cout << x;
    }
}