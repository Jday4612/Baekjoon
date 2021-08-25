#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    for(int i = m; i <= n; i++) {
        int t = 1;
        if(i > 1) {
            for(int j = 2; j < (int)sqrt(i) + 1; j++) {
                if(i % j == 0) {
                    t = 0;
                    break;
                }
            }
            if(t)
                cout << i << '\n';
        }
    }
    
    return 0;
}