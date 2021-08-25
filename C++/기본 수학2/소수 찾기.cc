#include <iostream>
using namespace std;

int main() {
    int n, x, cnt;
    cin >> n;
    cnt = n;
    
    for(int i = 0; i < n; i++) {
        cin >> x;
        
        if(x == 1) {
            cnt--;
            continue;
        }
        else {
            for(int j = 2; j < x; j++) {
                if(x % j == 0) {
                    cnt--;
                    break;
                }
            }
        }
    }
    cout << cnt;
}