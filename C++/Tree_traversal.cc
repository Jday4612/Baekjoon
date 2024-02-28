#include <iostream>
using namespace std;

void preorder(int inStart, int inEnd, int postStart, int postEnd);
int n, inorder[100001], postorder[100001], idx[100001];;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }

    for (int i = 1; i <= n; i++)
        cin >> postorder[i];

    preorder(1, n, 1, n);

    return 0;
}

void preorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inEnd < inStart || postEnd < postStart)
        return;

    int root = idx[postorder[postEnd]];
    int leftSize = root - inStart;

    cout << inorder[root] << " ";

    preorder(inStart, root - 1, postStart, postStart + leftSize - 1); // 왼쪽
    preorder(root + 1, inEnd, postStart + leftSize, postEnd - 1); // 오른쪽
}