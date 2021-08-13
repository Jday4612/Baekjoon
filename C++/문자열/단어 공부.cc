#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string apb = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", n;
    int max = 0;
    char num;
    
    cin >> n;
    for(int i = 0; i < n.length(); i++)
        n[i] = toupper(n[i]);
    
    for(int i = 0; i < apb.length(); i++) {
        int tmp = 0;
        for(int j = 0; j <= n.length(); j++) {
            if(n[j] == apb[i])
                tmp++;
        }
        
        if(max < tmp) {
            max = tmp;
            num = apb[i];
        }
        else if(max == tmp)
            num = '?';
    }
    
    cout << num;
    
    return 0;
}