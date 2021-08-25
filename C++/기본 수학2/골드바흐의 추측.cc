#include <iostream>
#include <cmath>
using namespace std;

bool get_num(int x) {
    for(int i = 2; i < (int)sqrt(x) + 1; i++) {
        if(x % i == 0)
            return true;
    }
    return false;
}

int main() {
    int t, n, a, b;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        cin >> n;
        
        a = n / 2;
        b = n - a;
        
        while(true) {
            if(get_num(a) || get_num(b)) {
                a--;
                b++;
                continue;
            }
            break;
        }
        cout << a << ' ' << b << '\n';
    }
    
    return 0;
}