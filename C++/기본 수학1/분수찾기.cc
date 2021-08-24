#include <iostream>
using namespace std;

int main() {
    int n, a = 1;
    cin >> n;
    
    while(n > a) {
        n -= a;
        a++;
    }
    
    if(a % 2 == 0)
        cout << n << "/" << a - n + 1;
    else
        cout << a - n + 1 << "/" << n;
    
    return 0;
}