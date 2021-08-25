#include <iostream>
using namespace std;

int main() {
    int n, t = 2;
    cin >> n;
    
    while(n > 1) {
        if(n % t == 0) {
            n /= t;
            cout << t << '\n';
        }
        else
            t++;
    }
    
    return 0;
}