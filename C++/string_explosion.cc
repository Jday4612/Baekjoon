#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string a, b, t = "";
    int a_len, b_len;

    cin >> a >> b;

    a_len = a.length();
    b_len = b.length();

    for (int i = 0; i < a_len; i++) {
        t += a[i];

        if (b_len <= t.length()) {
            bool check = true;

            for (int j = 0; j < b_len; j++) {
                if (t[t.length() - b_len + j] != b[j]) {
                    check = false;
                    break;
                }
            }

            if (check)
                t.erase(t.end() - b_len, t.end());
        }
    }

    if (t.empty())
        cout << "FRULA";
    else
        cout << t;

    return 0;
}