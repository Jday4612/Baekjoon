#include <iostream>
using namespace std;

int main() {
    int a, b, c, t;
    cin >> a >> b >> c;
    
    while(a != 0) {
        if(a > c) {
            t = c;
            c = a;
            a = t;
        }
        if(b > c) {
            t = c;
            c = b;
            b = t;
        }
        
        if(c*c == a*a + b*b)
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
        
        cin >> a >> b >> c;
    }
    
    return 0;
}