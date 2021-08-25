#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while(n != 0) {
        int cnt = 0;
        
        if(n == 1)
            cout << 1 << '\n';
        else {
            for(int i = n + 1; i <= 2*n; i++) {
                if(i % 2) {
                    for(int j = 3; j < (int)sqrt(i) + 1; j += 2) {
                        if(i % j == 0) {
                            cnt--;
                            break;
                        }
                    }
                    cnt++;
                }
            }
            cout << cnt << '\n';
        }
        
        cin >> n;
    }
    
    return 0;
}