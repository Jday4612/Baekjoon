#include <iostream>
using namespace std;

int main() {
    int n, x = 0;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        if(0 < i && i < 100)
            x++;
        else {
            if((i / 100) - (i % 100 / 10) == (i % 100 / 10) - i % 10)
                x++;
        }
    }
    cout << x;
}