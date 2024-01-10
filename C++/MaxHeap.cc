#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, x;
    priority_queue<int> heap;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x;

        if (x)
            heap.push(x);
        else {
            if (heap.empty())
                cout << "0\n";
            else {
                cout << heap.top() << "\n";
                heap.pop();
            }
        }
    }

    return 0;
}