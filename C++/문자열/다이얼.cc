#include <iostream>
using namespace std;

int main() {
    string n;
    int tmp = 0;
    cin >> n;
    
    for(int i = 0; i < n.length(); i++) {
        switch(n[i]) {
            case 'A': case 'B': case 'C':
                tmp += 3;
                break;
            case 'D': case 'E': case 'F':
                tmp += 4;
                break;
            case 'G': case 'H': case 'I':
                tmp += 5;
                break;
            case 'J': case 'K': case 'L':
                tmp += 6;
                break;
            case 'M': case 'N': case 'O':
                tmp += 7;
                break;
                
            case 'P': case 'Q': case 'R': case 'S':
                tmp += 8;
                break;
            case 'T': case 'U': case 'V':
                tmp += 9;
                break;
            case 'W': case 'X': case 'Y': case 'Z':
                tmp += 10;
                break;
        }
    }
    
    cout << tmp;
}