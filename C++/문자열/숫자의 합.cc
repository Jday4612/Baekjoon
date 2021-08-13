#include <iostream>
using namespace std;

int main() {
    int a, tmp = 0;
    char b;
    cin >> a;
    
    for(int i = 0; i < a; i++) {
        cin >> b;
        tmp += b - '0';
    }
    cout << tmp;
}