#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a;
        string b;
        cin >> a >> b;
        
        for(int j = 0; j < b.length(); j++) {
            for(int k = 0; k < a; k++) {
                cout << b[j];
            }
        }
        cout << "\n";
    }
    
    return 0;
}