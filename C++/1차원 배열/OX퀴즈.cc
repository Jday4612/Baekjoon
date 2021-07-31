#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n, cnt = 0, check = 0;
    cin >> n;
    
    char z[80];
    for(int i = 0; i < n; i++) {
        cin >> z;
        
        for(int i = 0; i < strlen(z); i++) {
            if(z[i] == 'O') {
                cnt++;
                check += cnt;
            }
            else if(z[i] == 'X')
                cnt = 0;
        }
        cout << check << '\n';
        cnt = 0; check = 0;
    }
    return 0;
}