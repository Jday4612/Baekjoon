#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    bool check = true;
    int tmp = 0;
    
    getline(cin, n);
    
    for(int i = 0; i < n.length(); i++) {
        if(n[i] == ' ')
            check = true;
        else if(check) {
            check = false;
            tmp++;
        }
    }
    
    cout << tmp;
    
    return 0;
}