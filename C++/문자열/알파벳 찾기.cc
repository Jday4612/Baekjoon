#include <iostream>
#include <string>
using namespace std;

int main() {
    string apb = "abcdefghijklmnopqrstuvwxyz";
    string n;
    cin >> n;
    
    for(int i = 0; i < apb.length(); i++) {
        cout << (int)n.find(apb[i]) << " ";
    }
    return 0;
}