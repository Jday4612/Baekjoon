#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    float z[n];
    
    for(int i = 0; i < n; i++)
        cin >> z[i];
    int m = 0;
    for(int i = 0; i < n; i++) {
        if(m < z[i])
            m = z[i];
    }
    
    for(int i = 0; i < n; i++) {
        z[i] = z[i] / m * 100;
    }
    
    float avr = 0;
    for(int i = 0; i < n; i++)
        avr += z[i];
    cout << avr / n;
}