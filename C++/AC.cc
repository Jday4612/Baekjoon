#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T, n, idx;
    bool r, e;
    string p, x;

    cin >> T;

    for (int i = 0; i < T; i++) {
        deque<int> arr;
        cin >> p >> n >> x;

        r = false, e = false, idx = 1;

        for (int j = 0; j < n; j++) {
            int pos = x.find_first_of(',', idx);

            if (pos == -1)
                pos = x.find_first_of(']', idx);

            arr.push_back(stoi(x.substr(idx, pos - idx)));
            idx = pos + 1;
        }

        for (char command : p) {
            if (command == 'R') {
                r = !r;
            }
            else if (command == 'D') {
                if (arr.empty()) {
                    e = true;
                    break;
                }

                if (r)
                    arr.pop_back();
                else
                    arr.pop_front();
            }
        }

        if (e)
            cout << "error\n";
        else {
            cout << "[";

            if (!arr.empty()) {
                if (r) {
                    cout << arr.back();
                    arr.pop_back();

                    while (!arr.empty()) {
                        cout << "," << arr.back();
                        arr.pop_back();
                    }
                }
                else {
                    cout << arr.front();
                    arr.pop_front();

                    while (!arr.empty()) {
                        cout << "," << arr.front();
                        arr.pop_front();
                    }
                }
            }

            cout << "]\n";
        }

    }

    return 0;
}