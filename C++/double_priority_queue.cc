#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T, k, n;
    char op;
    cin >> T;

    for (int i = 0; i < T; i++) {
        multiset<int> q;

        cin >> k;

        for (int j = 0; j < k; j++) {
            cin >> op >> n;

            if (op == 'I')
                q.insert(n);
            else { // 'D'
                if (q.empty())
                    continue;

                if (n == 1)
                    q.erase(--q.end());
                else
                    q.erase(q.begin());
            }
        }

        if (q.empty())
            cout << "EMPTY\n";
        else
            cout << *(--q.end()) << " " << *q.begin() << "\n";
    }

    return 0;
}