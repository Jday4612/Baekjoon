#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    stack<char> me;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z')
            cout << s[i];
        else {
            if (s[i] == '(')
                me.push(s[i]);
            else if (s[i] == '*' || s[i] == '/') {
                while (!me.empty() && (me.top() == '*' || me.top() == '/')) {
                    cout << me.top();
                    me.pop();
                }
                me.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-') {
                while (!me.empty() && me.top() != '(') {
                    cout << me.top();
                    me.pop();
                }
                me.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!me.empty() && me.top() != '(') {
                    cout << me.top();
                    me.pop();
                }
                me.pop();
            }
        }
    }

    while (!me.empty()) {
        cout << me.top();
        me.pop();
    }

    return 0;
}