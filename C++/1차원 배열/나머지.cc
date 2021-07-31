#include <iostream>
using namespace std;

int main() {
    int tmp;
    bool z[42] = {false};
    
    for(int i = 0; i < 10; i++) {
        cin >> tmp;
        tmp %= 42;
        z[tmp] = true;
    }
    
    int check = 0;
    for(int i = 0; i < 42; i++) {
        if(z[i] == true)
            check++;
    }
    cout << check;
}