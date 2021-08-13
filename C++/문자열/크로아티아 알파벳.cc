#include <iostream>
#include <string>
using namespace std;

int main() {
    string apb[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string tmp;
    cin >> tmp;
    
    int check = 0;
    
    for(int i = 0; i < tmp.length(); i++) {
        for(int j = 0; j < 8; j ++) {
            string a = "";
            for(int k = 0; k < apb[j].length(); k++)
                a += tmp[i+k];
            
            if(a == apb[j]) {
                check++;
                i += apb[j].length()-1;
                break;
            }
            
            if(j == 7)
                check++;
        }
    }
    
    cout << check;
}