#include <iostream>
using namespace std;

int main() {
    int T, x, y;
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        cin >> x >> y;
        
        int a = 1, b = 1, z = y - x;
        while(z > 0) {
            z -= a;
            a++;
            
            if(z > b) {
                z -= b;
                b++;
            }
        }
        cout << a + b - 2 << '\n';
    }
    
    return 0;
}