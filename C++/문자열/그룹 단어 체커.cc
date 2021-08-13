#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, cnt;
    bool check = false;
    string tmp;
    cin >> n;
    cnt = n;
    
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        
        for(int j = 0; j < tmp.length(); j++) {
            if(tmp[j] != tmp[j+1]) {
                for(int k = j + 1; k < tmp.length(); k++) {
                    if(tmp[j] == tmp[k]) {
                        check = true;
                        break;
                    }
                }
            }
            if(check == true) {
                check = false;
                cnt--;
                break;
            }
        }
    }
    
    cout << cnt;
}