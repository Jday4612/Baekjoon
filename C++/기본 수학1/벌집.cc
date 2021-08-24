#include <iostream>
using namespace std;

int main() {
    int n, a = 1, b = 6, c = 1;
    cin >> n;
    
    while(n > a) {
        a += b;
        b += 6;
        c++;
    }
    cout << c;
    
    return 0;
}