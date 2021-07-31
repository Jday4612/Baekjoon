#include <iostream>
using namespace std;

int main() {
    int c, n;
    cin >> c;
    
    for(int i = 0; i < c; i++) {
        cin >> n;
        int num[n];
        float avr = 0;
        
        for(int j = 0; j < n; j++) {
            cin >> num[j];
            avr += num[j];
        }
        avr /= n;
        
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(avr < num[j])
            cnt++;
        }
        
        float x = (float)cnt * 100 / n;
        
        cout << fixed;
        cout.precision(3);
        cout << x << "%\n";
    }
}