#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    
    while(true) {
        if(n < 0) {
            cout << -1;
            break;
        }
        if(n % 5 == 0) {
            cout << n / 5 + cnt;
            break;
        }
        n -= 3;
        cnt++;
    }

    return 0;
}