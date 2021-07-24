#include <iostream>
using namespace std;

int main() {
    int n, a, b, c, x = 0;
    cin >> n;
    
    if(n < 10)
        n *= 10;
    c = n;
    
    while(true) {
        a = c / 10;
        b = c % 10;
        c = (b * 10) + (a+b) % 10;
        x++;
        
        if(n == c)
            break;
    }
    cout << x;
}